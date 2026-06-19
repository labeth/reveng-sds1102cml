# SDS1102CML+ reverse-engineering findings

Working notes from extracting and running the vendor firmware. The hardware
interface contracts proper are documented in the open repo's `specs/`; this file
covers the **binary/firmware-package** RE and the **runtime** RE that depends on the
proprietary bytes here.

---

## 1. The `.ADS` firmware-update container

`ads/CML+_P25.ADS` (6,621,932 bytes, package "SDS1000CML+ V6.01.01.25") is a
**scrambled wrapper around a ZIP**. It is *not* encrypted — the whole-file high
entropy comes from the scramble + the compressed ZIP members. The scramble is the
**same family as the on-flash calibration blob** (open `specs/07 §2.1`,
`FUN_00072584`): reverse + NOT-back-half + NOT-triangular-indices.

**De-scramble recipe** (implemented in `open/tools/extract_siglent_cml_ads.py`):

```
reverse the entire file
XOR the byte at every triangular index (0,1,3,6,10,15,...) with 0xff
XOR (NOT) the back half, beginning at (len - 0x70) // 2
the ZIP payload begins at offset 0x34
```

The wrapped ZIP has a **valid local-file-header stream but no end-of-central-
directory record** (so stock `unzip` fails with "EOCD not found"). The extractor
walks the `PK\x03\x04` local headers directly and inflates each member.

**Open item — `sds1000a_al.bin`**: one member (the auxiliary FPGA image) fails to
inflate ("invalid block type") — it appears to carry an *extra* transform block
(suspected `0x2800`/`0x1400`-aligned). Isolated; does not affect the other 24
members. Not yet resolved.

### Extracted inventory (`firmware/`)

| File | Size | What |
|------|------|------|
| `MLO` | 79 KB | SPL (1st-stage bootloader) |
| `u-boot.img` | 362 KB | U-Boot (uImage) |
| `SDS1000_arm.app` | 3.27 MB | **the GUI application** (the central RE target) |
| `ro_uImage` / `rw_uImage` | 2.3 MB ea | Linux `3.2.0+` kernels (uImage); the `/dev/Gpmc` + `/dev/fpga_key` drivers are in-kernel |
| `sds1000_fpga.rbf` | 368 KB | acquisition-FPGA bitstream (Altera passive-serial) |
| `datafs.img` | 2 MB | `datafs` UBI volume (user data) |
| `firmdata0.img` | 2 MB | `firmdata0` UBI volume — **skeleton in the update** (only `version.txt`, dated 2014-12-13); the real per-unit `calibration.dat` is NOT shipped in the update (it lives on the unit's flash, per `specs/07`) |
| `cfbcopyarea/cfbfillrect/cfbimgblt/da8xx-fb.ko` | | framebuffer module stack (insmod'd by the app) |
| `g_usbtmc/gpib/musb_hdrc/ti81xx/udc-core.ko` | | USB-TMC / GPIB / USB gadget modules |
| `libglog.so.0` | 712 KB | Google logging — **not stripped** (has symbols; useful) |
| `siglentlib.sh` / `update.sh` / `upgrade.sh` | | shell helpers |
| `NSP_config_upgrade_info.xml` | | upgrade-id gate (`[10000,10499]`, `specs/08 §6`) |

---

## 2. `SDS1000_arm.app` triage

```
ELF 32-bit LSB executable, ARM, EABI5 v1 (SYSV), dynamically linked,
interpreter /lib/ld-linux.so.3, for GNU/Linux 2.6.16, stripped
md5  e1bd88fbdf1c1b35d8a838063f7cab71
entry 0xd310   image base 0x00008000
NEEDED: libpthread libxml2 librt libglog libstdc++ libm libgcc_s libc
```

- **This md5 (`e1bd88fb`) is the exact binary the open `specs/` were RE'd from**
  (`specs/06 §8` cites it vs the live unit's `8d9e216e` build). Image base `0x8000`,
  so every `FUN_xxxxxx` address in the specs is `0x8000 + file_offset` here.
- **Dynamically linked** ⇒ `LD_PRELOAD` device interception works on it (unlike our
  static Go app), which is how we bridge its device I/O to the sim.
- **C++ app**, glog-based logging. Recovered source-module names (from strings):
  `module.cpp`, `nsp_os.cpp`, `dev_interface.cpp`, `dev_interpreter.cpp`,
  `dev_scpi.cpp`, `dcHandle_usbtmc.cpp`, `dev_eth_class.cpp`, `dev_file_handle.cpp`,
  `dev_flash_class.cpp`, `dev_system_class.cpp`, `dev_xml_class.cpp`,
  `dev_buzzer.cpp`, `crc_lib.cpp`, `err_lib_error.cpp`, `message.cpp`.

---

## 3. Running the vendor app under qemu (clean-room, no hardware)

The app **loads and runs** on an x86_64 host via `qemu-arm-static` + an armel
sysroot (it is the dynamic-ELF path; full-system QEMU is not required to *run* it —
only to model the `/dev/mem` MMIO path, which this app never uses).

Sysroot assembly (see `sysroot-setup/`):
- `arm-linux-gnueabi-gcc` (Ubuntu) brings an armel sysroot at `/usr/arm-linux-gnueabi/`
  with `ld-linux.so.3` + glibc + libstdc++ + libpthread/librt/libm/libgcc_s.
- `libxml2.so.2` (+ `libicu72`, `liblzma5`, `zlib1g`) fetched as Debian **armel**
  `.deb`s (`apt-get download -o APT::Architecture=armel ...`, `dpkg-deb -x`).
- `libglog.so.0` from `firmware/`.

Run: `LD_LIBRARY_PATH=/lib qemu-arm-static -L <sysroot> ./SDS1000_arm.app`.

**Observed**: the app resolves all libs, initialises glog ("Creat Log",
`module.cpp:569`), then proceeds into device/FS bring-up — it opens `/dev/fpga_key`
("open keyboard interrupt" on failure, per `specs/02 §3`), writes the eHRPWM/gpio
sysfs nodes, sources `/usr/lib/siglentlib.sh`, and mkdir's its `usr/` work dirs.
i.e. it runs real app code and stops only where the device/filesystem environment is
absent — which the sim provides (a chroot rootfs + an `LD_PRELOAD` shim bridging
`/dev/Gpmc` to the Go `sim/fpga` core; in progress, traces will land in `reglogs/`).

---

## 4. Spec validation against the real binary

Strings/symbols of `firmware/SDS1000_arm.app` **confirm the open specs** with no
discrepancies on:
- **Device nodes**: `/dev/Gpmc`, `/dev/fb0`, `/dev/fpga_key`, `/dev/spidev1.0`,
  `/dev/spidev1.1`, `/dev/g_usbtmc`, `/dev/usb-gpib` (specs/02/03/04/06).
- **FPGA load gate**: `Load Fpga Success!` / `Load Fpga Failed!` (specs/04 §3).
- **GPMC open error**: `>>>>>CHWAccess::gpmc open failed!` (specs/02 §5).
- **Keyboard log**: `/dev/keyboard.dat` (specs/02 §8).
- **sysfs echoes** (verbatim): `echo 7 > /sys/class/gpio/export`,
  `…/gpio7/value`, `…/gpio113/value`,
  `…/omap/ehrpwm.0/pwm/ehrpwm.0:0/{request,period_freq=10000,duty_percent=50,run}`
  (specs/02/03/06).
- **SCPI**: `C1:VDIV`, `TDIV`, `SARA`, `WFSU` (specs/01).
- **Config paths**: `/usr/bin/siglent/firmdata0/Siglent_CML.cfg`,
  `/usr/bin/siglent/usr/config_file/Siglent_CML.cfg` (specs/07).

---

## 5. Ghidra static analysis

Setup (host): JDK 21 + Ghidra 12.1.2 (`~/ghidra/ghidra_12.1.2_PUBLIC/`). Headless:
`support/analyzeHeadless`. The app was imported + auto-analysed into project
`~/ghidra-projects/SDS1102` (language `ARM:LE:32:v8:default`; **5432 functions**).
> Ghidra 12 dropped Jython — Python scripts need PyGhidra (`pip install pyghidra`);
> Java GhidraScripts work headless with no extra setup (see `ghidra-scripts/`).

**Spec↔binary mapping confirmed** (`ghidra-scripts/ValidateSpecAddrs.java`): every
spec-cited `FUN_xxxxxx` resolves to a function at exactly that address (entry ==
`0x8000 + offset`):

| spec `FUN_` | role (spec) | resolved |
|---|---|---|
| `000cc224` | GPMC read primitive (04 AppxA) | ✓ entry `0xcc224`, 152 B |
| `000cc184` | PLANE-A byte writer `strb#1` (04 AppxA) | ✓ `0xcc184`, 152 B |
| `001ae850` | coupling writer (04 §13.6) | ✓ `0x1ae850`, 60 B |
| `001b05c8` | divisor class mapper (04 §5.4) | ✓ `0x1b05c8`, 232 B |
| `001ae530` | `0x44` enable strobe (04 §5) | ✓ `0x1ae530`, 44 B |
| `0021371c` | `0x35` run/mode writer (04 §5) | ✓ `0x21371c` |
| `001b2998` | front-end relay assembler (06 §8) | ✓ `0x1b2998`, 2436 B |
| `00074fd4` | `calibration.dat` reader 0xac0 (07 §2.1) | ✓ `0x74fd4`, 408 B |

**Decompile of `FUN_001ae850` confirms spec 04 §13.6 verbatim** (coupling = one
`&3`-masked write to the `0x22` selector, NO `0x23` strobe):

```c
void FUN_001ae850(byte param_1) {
  FUN_001b3500(DAT_001ae88c, param_1 & 3);  // DAT_001ae88c = the 0x22 sel; FUN_001b3500 = PLANE-A byte writer
  return;
}
```

This makes the binary a live oracle for confirming/correcting the specs: any
`FUN_` can be decompiled headless and checked against the spec text.

## 6. Open RE threads

- Resolve the `sds1000a_al.bin` ZIP-member transform (extra `0x2800`/`0x1400` block).
- Capture + analyse the runtime `/dev/Gpmc` reglog (god-mode trace) → compare the
  vendor's real drive sequence against `sim/fpga` and `specs/04`; fold corrections
  back into the specs (open repo) and the sim.
- Disassemble the in-kernel `Gpmc`/`fpga_key` drivers from `ro_uImage` (the ioctl
  struct copy, the single-open guard, CSVALID teardown) to confirm `specs/02/04 §2`.
- Per-unit `calibration.dat` is not in the update — pull from the unit to validate
  `sim/storage`'s checksum+scramble against real data.

---

## Vendor-app E2E validation against the sim (2026-06-19)

Ran the unmodified `SDS1000_arm.app` under qemu-arm + `devshim.so` + `simd` (wrapping
`sim/fpga`), fed it simulated signals via the new `simd -signal`, and exercised it
through display capture + VXI-11/SCPI across modes. **Result: the sim is register-
faithful; the vendor validates E2E for every reachable path. The one path that does
NOT produce output — the waveform trace / `WF? DAT2` / measurements — is blocked by
vendor-internal GUI state, not by the sim.**

**What validated (works against the sim):**
- Boot + full GUI render (graticule, UTILITY menu, "Armed", CH1 100mV/M500µs, trigger
  marker, freq counter). The single-page `/dev/fb0` fix is confirmed live:
  `g_vinfo.yres=480`, `mmap /dev/fb0 (768000 bytes)` (not the old 2-page 1,536,000).
- Main loop stable indefinitely (exit 124 = timeout-killed).
- VXI-11/SCPI dispatcher returns CORRECT values matching the display + specs:
  `*IDN? → Siglent,SDS115X,...,6.01.01.25`; `TDIV? → 5.00E-04s`; `C1:VDIV? → 1.00E-01V`;
  `SARA? → 1.250MSa` (exactly spec 04 §8.3 for 500µs/div); `SANU? → 20000`. `TDIV` set
  commands take effect (changed to 1.00E-01s).
- Both acquisition register loop-classes driven exactly per the decompile: the §5.0a
  GUI free-run loop (`0x3c/0x3d/0x3e/0x58` + `0x16` + `0x39`-poll ~4000×) and, with
  `simd -trigger`, the cycling done bit (`0x39`: done → not-done×7 → done) + the
  capture-class arm (`0x21=0xC0/0xC3`). At fast TDIV the §5.0c MEASUREMENT branch
  (`0x21=0x05`, `0x38` cycling `008f→00af`, `0x3a/0x3b` position) — all faithful.

**What is blocked (and WHY — decisive, decompile-backed):** every path that needs
actual SAMPLE DATA blocks — the trace never draws, and `C1:WF? DAT2`, `C1:WF? DESC`,
`C1:PAVA?`, and `AUTO_SETUP` all time out. The vendor reads **zero** sample data
(`0x41/0x59` roll, `0x30-0x34` deep, `0x38` status are NEVER read) regardless of
trigger mode (`TRMD AUTO`), timebase (tested 500µs free-run AND 100ms roll), or
`-trigger`. The vendor's sample-read + draw lives in `FUN_0020af00`/`FUN_0021eb08`,
reached only when the per-tick dispatcher `FUN_000d3148` takes its acquisition branch
— gated by **app-internal state** (the timebase loop-class `FUN_00219abc`, the
display-object pointer compare `*0x434af4 == 0x433390` choosing deep-drain vs the
MEASUREMENT branch, and the dispatcher flags `*DAT_000d3254+0x20`, `*DAT_000d3264`).
**None of these is an FPGA register response** — the RE pass confirmed no `0x39`/`0x38`
value or SCPI command flips them; they are set by **front-panel acquisition-mode /
menu navigation**. The vendor boots headless into the UTILITY/Counter view where the
waveform-acquisition object is not the active display object, so the sample subsystem
never runs. A held `0x39=1` is the worst case (forces `FUN_00218098 → 0xffffffff →
no-draw`); `simd -trigger` correctly presents the bit5-leads-bit0 edge the capture FSM
needs, but the display-object gate is upstream and never reached.

**The blocker is the front-panel key map.** The vendor reads keys only on a SIGIO IRQ
(`/dev/fpga_key`), never polling the matrix (`0x64-0x67` never read in the trace), and
the `(row,col) → labelled-button` map is **not in the firmware** (spec 02 §8 — needs
one-key captures from a physical unit). So navigating the GUI to activate the waveform
object requires either the unit's key map or a brute-force key-injection sweep
(inject each of the 64 matrix positions + raise SIGIO, observe which activates
acquisition). Harness: `tmp/run/run-vendor.sh` (signal via `SIGNAL=...`), `tmp/run/exp.sh`.
