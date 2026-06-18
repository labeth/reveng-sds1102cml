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

## 5. Open RE threads

- Resolve the `sds1000a_al.bin` ZIP-member transform (extra `0x2800`/`0x1400` block).
- Capture + analyse the runtime `/dev/Gpmc` reglog (god-mode trace) → compare the
  vendor's real drive sequence against `sim/fpga` and `specs/04`; fold corrections
  back into the specs (open repo) and the sim.
- Disassemble the in-kernel `Gpmc`/`fpga_key` drivers from `ro_uImage` (the ioctl
  struct copy, the single-open guard, CSVALID teardown) to confirm `specs/02/04 §2`.
- Per-unit `calibration.dat` is not in the update — pull from the unit to validate
  `sim/storage`'s checksum+scramble against real data.
