# reveng-sds1102cml — RE corpus (PRIVATE)

Reverse-engineering materials for the **Siglent SDS1102CML+** (SDS1000CML+/DL+
family, TI AM335x, Linux 3.2) that **cannot go in the open repo** — the proprietary
vendor firmware binaries, the firmware-update container, runtime register traces,
and disassembly/analysis notes.

> ⚠️ **Proprietary.** Everything under `firmware/` and `ads/` is Siglent's
> copyrighted firmware, extracted from a vendor `.ADS` update package. This repo is
> **private**; do not publish these bytes. The clean-room re-implementation, the
> interface specs, and the extraction *tool* live in the open repo
> (`../open-sds1102cml`, MIT) — only the vendor bytes and raw RE artifacts live here.

## Layout

```
FINDINGS.md          the RE writeup (.ADS format, extraction, binary triage,
                     qemu run setup, spec-validation results, C++ module map)
ads/                 CML+_P25.ADS (the scrambled update container) + the vendor PDFs
firmware/            the extracted firmware components (the RE targets):
                       SDS1000_arm.app    the GUI application ELF (the central target)
                       ro_uImage/rw_uImage Linux 3.2 kernels (in-kernel Gpmc/fpga_key drivers)
                       *.ko               loadable modules (da8xx-fb, g_usbtmc, ...)
                       sds1000_fpga.rbf   the acquisition-FPGA bitstream
                       datafs.img/firmdata0.img  UBI volume images
                       libglog.so.0       a runtime dep (not stripped — has symbols)
                       *.sh / *.xml       update scripts + config
analysis/            byte-level analysis scripts used to characterise the .ADS
reglogs/             runtime /dev/Gpmc register traces (god-mode reglog) from running
                     the vendor app under qemu against the sim
sysroot-setup/       notes/scripts to assemble the armel qemu run environment
```

## Relationship to the open repo (`../open-sds1102cml`)

- **Specs** (`open/specs/01..08`) — the reverse-engineered interface contracts. Were
  RE'd from `firmware/SDS1000_arm.app` (md5 `e1bd88fb`, image base `0x8000`), so every
  `FUN_xxxxxx` address in the specs maps directly into this binary.
- **`open/tools/extract_siglent_cml_ads.py`** — the clean-room extractor that turns
  `ads/CML+_P25.ADS` into `firmware/`.
- **`open/sim/`** — the clean-room Go emulator the vendor app is driven against.

See **FINDINGS.md** for the full writeup.
