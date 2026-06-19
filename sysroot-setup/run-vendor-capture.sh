#!/bin/bash
# run-vendor-capture.sh — drive the REAL vendor app into its DEEP/TRIGGERED capture
# path (TRMD SINGLE -> FUN_0020af00 -> 0x21=0xC8 latch + 0x30-0x34 drain) and capture
# the register sequence. Unlike run-vendor.sh this:
#   - runs simd with -trigger (NORM phase: armed frames report 0x38 bit5 + 0x3a/0x3b
#     position before done, so the deep FSM proceeds to drain),
#   - pins the shim's VXI-11 UDP DEVICE_CORE port (DEVSIM_RPC_UDP_PORT) so a host SCPI
#     client can reach the vendor's dispatcher with no portmapper,
#   - runs the vendor in the BACKGROUND, waits for boot, then sends SCPI to force a
#     single/triggered capture, then snapshots the drain reglog.
set -u
REPO=/mnt/c/Users/henri/Documents/ws/open-sds1102cml
RUN=$REPO/tmp/run
ROOT=$REPO/tmp/root
BOOT=${1:-14}      # seconds to let the app boot before driving SCPI
DWELL=${2:-12}     # seconds to keep running after SCPI so the drain lands
SOCK=@simfpga
RPC_UDP_PORT=42811
REGLOG=$RUN/reglog.txt
DEEPLOG=$RUN/reglog-deep.txt
FB=$RUN/fb.raw
SHIMLOG=$RUN/shim.log
APPLOG=$RUN/app.log

echo "== build simd (-trigger) + devshim.so =="
( cd "$REPO/sim" && go build -o "$RUN/simd" ./cmd/simd/ ) || { echo "simd build failed"; exit 1; }
arm-linux-gnueabi-gcc -shared -fPIC -O2 -U_FORTIFY_SOURCE \
    -o "$RUN/devshim.so" "$REPO/sim/preload/devshim.c" -ldl -lpthread || { echo "shim build failed"; exit 1; }

echo "== refresh chroot rootfs =="
cp "$REPO/tmp/extracted/SDS1000_arm.app" "$ROOT/usr/bin/siglent/"
cp "$REPO/tmp/extracted/sds1000_fpga.rbf" "$ROOT/usr/bin/siglent/fpga/" 2>/dev/null
cp "$REPO/tmp/extracted/siglentlib.sh" "$ROOT/usr/lib/"
cp "$RUN/devshim.so" "$ROOT/devshim.so"
cp "$(command -v qemu-arm-static)" "$ROOT/usr/bin/qemu-arm-static"
mkdir -p "$ROOT/tmp"
echo a | sudo -S sh -c "
  mkdir -p '$ROOT/dev'
  [ -e '$ROOT/dev/null' ] || mknod -m 666 '$ROOT/dev/null' c 1 3
  [ -e '$ROOT/dev/zero' ] || mknod -m 666 '$ROOT/dev/zero' c 1 5
  [ -e '$ROOT/dev/random' ] || mknod -m 666 '$ROOT/dev/random' c 1 8
  [ -e '$ROOT/dev/urandom' ] || mknod -m 666 '$ROOT/dev/urandom' c 1 9
  [ -e '$ROOT/dev/tty' ] || mknod -m 666 '$ROOT/dev/tty' c 5 0
  [ -e '$ROOT/dev/tty0' ] || mknod -m 666 '$ROOT/dev/tty0' c 4 0
" 2>/dev/null

echo "== start simd (-trigger, $SOCK) =="
pkill -f "$RUN/simd" 2>/dev/null; sleep 0.3
"$RUN/simd" -sock "$SOCK" -reglog "$REGLOG" -trigger >"$RUN/simd.log" 2>&1 &
SIMD_PID=$!
sleep 0.5
kill -0 $SIMD_PID 2>/dev/null || { echo "simd exited early"; cat "$RUN/simd.log"; exit 1; }
echo "   simd pid=$SIMD_PID"

TOTAL=$((BOOT + DWELL + 6))
echo "== run vendor app (background, ${TOTAL}s guard); SCPI at +${BOOT}s =="
echo a | sudo -S timeout "$TOTAL" \
    chroot "$ROOT" /usr/bin/qemu-arm-static \
        -E LD_LIBRARY_PATH=/lib:/usr/lib:/usr/lib/arm-linux-gnueabi \
        -E LD_PRELOAD=/devshim.so \
        -E DEVSIM_TARGET=SDS1000_arm.app \
        -E SIMSOCK=@simfpga \
        -E DEVSIM_FB=/tmp/fb.raw \
        -E DEVSIM_SHIMLOG=/tmp/shim.log \
        -E DEVSIM_RPC_UDP_PORT=$RPC_UDP_PORT \
        -E HOME=/usr/bin/siglent \
        /usr/bin/siglent/SDS1000_arm.app >"$APPLOG" 2>&1 &
APP_WRAP_PID=$!

echo "== waiting ${BOOT}s for boot + RPC server =="
sleep "$BOOT"
cp "$ROOT/tmp/shim.log" "$SHIMLOG" 2>/dev/null
echo "   RPC ports from shim log:"; grep 'RPC .* server' "$SHIMLOG" 2>/dev/null | sed 's/^/   /'
echo "   app alive? procs=$(ps aux 2>/dev/null | grep -E 'SDS1000_arm|qemu-arm-static' | grep -v grep | wc -l)"
echo "   ss udp 42811 (root):"; echo a | sudo -S ss -lunp 2>/dev/null | grep 42811 | sed 's/^/      /' || echo "      (not listening per ss)"
echo "   raw UDP reachability probe:"
timeout 4 python3 - "$RPC_UDP_PORT" <<'PYEOF' 2>&1 | sed 's/^/      /'
import socket,struct,sys
port=int(sys.argv[1])
s=socket.socket(socket.AF_INET,socket.SOCK_DGRAM); s.settimeout(3)
# null procedure (proc 0) call to DEVICE_CORE — should get an RPC reply if reachable
body=struct.pack(">IIIIII",1,0,2,0x607af,1,0)+struct.pack(">IIII",0,0,0,0)
s.sendto(body,("127.0.0.1",port))
try:
    d,_=s.recvfrom(4096); print("got %d-byte RPC reply (REACHABLE)"%len(d))
except Exception as e:
    print("no reply:",e)
PYEOF

# mark the reglog so we can isolate the post-SCPI window
MARK=$(grep -cE '^[RW]' "$REGLOG" 2>/dev/null || echo 0)
echo "   reglog lines before SCPI: $MARK"

# The acquisition thread picks its loop from the TIMEBASE CLASS byte (+0x60 =
# FUN_00219abc): a FAST TDIV (index < 6, i.e. <= 50 ns/div) makes +0x60==1 ->
# FUN_0020d5c4 -> FUN_0020b6d4 case 5 -> arm 0xC0/0xC3 -> poll FUN_00218098 ->
# latch 0x21=0xC8 -> drain 0x30-0x34 (RE: ac8892321aa198222). The GUI boots at 500
# us/div (idx 17 -> +0x60==0, free-run). So set a fast TDIV FIRST, then RUN, then
# read the wave. TDIV/RUN are set commands (no blocking reply). TRMD SINGLE blocks
# until a capture lands (it waits while(*DAT_00256730 != 1)) -> long client timeout.
echo "== sending SCPI capture commands to vendor (udp/$RPC_UDP_PORT) =="
SCPI() { echo "---- $1 ----"; timeout "${2:-12}" python3 "$RUN/vxi11_udp.py" $RPC_UDP_PORT "$1" 2>&1 | grep -E 'RESPONSE|error=|bytes|timed out' | sed 's/^/   /'; }
SCPI "TDIV 5E-9" 6       # fastest class -> capture-class loop (idx 2)
sleep 2
SCPI "TRMD NORM" 6       # triggered (NORM) run mode
SCPI "ACQW SAMPLING" 6   # acquisition mode (try select the deep/normal capture object)
SCPI "MSIZ 14K" 6        # memory depth (deep frame)
sleep 2
for i in 1 2 3 4; do SCPI "C1:WF? DAT2" 8; sleep 1; done   # pull the display waveform repeatedly
SCPI "SARA?" 6
SCPI "SANU? C1" 6
SCPI "TDIV 2E-8" 6       # another fast class (idx 4)
sleep 2
for i in 1 2 3; do SCPI "C2:WF? DAT2" 8; sleep 1; done

echo "== dwell ${DWELL}s so the drain lands =="
sleep "$DWELL"

# snapshot the post-SCPI reglog window
echo "== drain reglog window (lines after $MARK) =="
awk -v m="$MARK" 'BEGIN{c=0} /^[RW]|^R cs1 30-34/{c++} c>m{print} c<=m && !/^[RW]/{next}' "$REGLOG" 2>/dev/null > "$DEEPLOG"
tail -n +"$((MARK+1))" "$REGLOG" 2>/dev/null | grep -nE '00c8|0021 = 00c8|30-34 |003a|003b|0038 ' | head -40 || true

echo "== stop =="
kill $APP_WRAP_PID 2>/dev/null
echo a | sudo -S pkill -f SDS1000_arm.app 2>/dev/null
kill -INT $SIMD_PID 2>/dev/null; wait $SIMD_PID 2>/dev/null

cp "$ROOT/tmp/fb.raw" "$FB" 2>/dev/null
cp "$ROOT/tmp/shim.log" "$SHIMLOG" 2>/dev/null

echo "== results =="
echo "  reglog        : $REGLOG ($(grep -cE '^[RW]' "$REGLOG" 2>/dev/null) accesses)"
echo "  C8 latches    : $(grep -c '0021 = 00c8' "$REGLOG" 2>/dev/null)"
echo "  deep drains   : $(grep -c 'deep sample-port' "$REGLOG" 2>/dev/null)"
echo "  bit5 triggered: $(grep -c '0038 = 00af' "$REGLOG" 2>/dev/null)"
echo "  trig-pos reads: $(grep -cE '003a |003b ' "$REGLOG" 2>/dev/null)"
