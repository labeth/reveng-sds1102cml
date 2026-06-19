#!/usr/bin/env python3
"""
vxi11_udp.py - minimal UDP VXI-11 (ONC/Sun RPC) client for the vendor app running
under the devshim's mini RPC server (which is UDP-only, no portmapper). Talks
directly to a PINNED UDP port (DEVSIM_RPC_UDP_PORT in the shim) on 127.0.0.1.

Sends create_link -> device_write(<scpi>) -> device_read, so we can drive the
running vendor app's VXI-11 dispatcher with arbitrary SCPI (e.g. TRMD SINGLE) and
read the reply. Used to push the vendor into its DEEP/TRIGGERED capture path.

  vxi11_udp.py <port> "TRMD SINGLE"
  vxi11_udp.py <port> "C1:WF? DAT2" --raw out.bin
"""
import argparse
import socket
import struct
import sys

CORE_PROG, CORE_VERS = 0x0607AF, 1


def xdr_str(b):
    if isinstance(b, str):
        b = b.encode()
    return struct.pack(">I", len(b)) + b + b"\x00" * ((-len(b)) % 4)


class RpcUdp:
    def __init__(self, host, port, timeout=8):
        self.addr = (host, port)
        self.sock = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
        self.sock.settimeout(timeout)
        self.xid = 0

    def call(self, prog, vers, proc, args):
        self.xid += 1
        body = struct.pack(">IIIIII", self.xid, 0, 2, prog, vers, proc)
        body += struct.pack(">IIII", 0, 0, 0, 0)  # null cred + null verf
        body += args
        self.sock.sendto(body, self.addr)
        out, _ = self.sock.recvfrom(65536)
        (rxid, mtype, rstat) = struct.unpack_from(">III", out, 0)
        (vf, vl) = struct.unpack_from(">II", out, 12)
        off = 20 + vl
        (astat,) = struct.unpack_from(">I", out, off)
        if mtype != 1 or rstat != 0 or astat != 0:
            raise RuntimeError(f"rpc reply not OK type={mtype} rstat={rstat} astat={astat}")
        return out[off + 4:]

    def close(self):
        self.sock.close()


def scpi(host, port, command, raw_out=None):
    c = RpcUdp(host, port)
    try:
        # create_link(clientId=1, lockDevice=0, lock_timeout=0, device="inst0")
        r = c.call(CORE_PROG, CORE_VERS, 10,
                   struct.pack(">iII", 1, 0, 0) + xdr_str("inst0"))
        error, lid, abortPort, maxRecv = struct.unpack_from(">iIII", r, 0)
        print(f"create_link -> error={error} lid={lid} maxRecvSize={maxRecv}")
        if error != 0:
            return 1
        # device_write(lid, io_timeout, lock_timeout, flags=END(8), data)
        r = c.call(CORE_PROG, CORE_VERS, 11,
                   struct.pack(">iIIi", lid, 5000, 0, 8) + xdr_str(command + "\n"))
        werr, wsize = struct.unpack_from(">iI", r, 0)
        print(f"device_write({command!r}) -> error={werr} size={wsize}")
        # device_read
        chunks = b""
        for _ in range(64):
            try:
                r = c.call(CORE_PROG, CORE_VERS, 12,
                           struct.pack(">iIIIiI", lid, maxRecv or 4096, 5000, 0, 0, 0))
            except socket.timeout:
                print("device_read timed out (no reply)")
                break
            rerr, reason, dlen = struct.unpack_from(">iiI", r, 0)
            payload = r[12:12 + dlen]
            chunks += payload
            if rerr != 0 or reason != 0:
                break
        print(f"device_read -> {len(chunks)} bytes")
        if raw_out:
            with open(raw_out, "wb") as f:
                f.write(chunks)
            print(f"raw -> {raw_out}; first 64B: {chunks[:64]!r}")
        else:
            try:
                print(f"*** RESPONSE: {chunks.decode(errors='replace').strip()}")
            except Exception:
                print(f"*** RESPONSE (binary, {len(chunks)}B): {chunks[:80]!r}")
        c.call(CORE_PROG, CORE_VERS, 23, struct.pack(">i", lid))  # destroy_link
        return 0
    finally:
        c.close()


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("port", type=int)
    ap.add_argument("command", nargs="?", default="*IDN?")
    ap.add_argument("--host", default="127.0.0.1")
    ap.add_argument("--raw")
    a = ap.parse_args()
    return scpi(a.host, a.port, a.command, a.raw)


if __name__ == "__main__":
    sys.exit(main())
