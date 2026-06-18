# Ghidra (Jython) headless script: validate that the open-repo spec's FUN_ addresses
# map to real functions in SDS1000_arm.app (md5 e1bd88fb, image base 0x8000), and
# decompile one to confirm it matches the spec text. Run:
#   analyzeHeadless ~/ghidra-projects SDS1102 -process SDS1000_arm.app \
#       -scriptPath <this dir> -postScript validate_spec_addrs.py -noanalysis
from ghidra.app.decompiler import DecompInterface

fm = currentProgram.getFunctionManager()
af = currentProgram.getAddressFactory().getDefaultAddressSpace()
print("=== FUNC_COUNT %d ===" % fm.getFunctionCount())

# (vaddr, spec reference) — vaddr = image_base(0x8000) + file_offset, i.e. the FUN_ id.
checks = [
    (0x000cc224, "FUN_000cc224 GPMC read primitive (spec04 AppxA)"),
    (0x000cc184, "FUN_000cc184 PLANE-A byte writer / strb#1 (spec04 AppxA)"),
    (0x001ae850, "FUN_001ae850 coupling writer 0x22 &3 (spec04 13.6)"),
    (0x001b05c8, "FUN_001b05c8 divisor class mapper (spec04 5.4)"),
    (0x001ae530, "FUN_001ae530 0x44 enable strobe (spec04 5)"),
    (0x0021371c, "FUN_0021371c 0x35 run/mode writer (spec04 5)"),
    (0x001b2998, "FUN_001b2998 front-end relay assembler (spec06 8)"),
    (0x00074fd4, "FUN_00074fd4 calibration.dat reader 0xac0 (spec07 2.1)"),
]
for a, ref in checks:
    f = fm.getFunctionContaining(af.getAddress(a))
    if f:
        print("OK   0x%08x -> %s entry=0x%x size=%d : %s" % (
            a, f.getName(), f.getEntryPoint().getOffset(), f.getBody().getNumAddresses(), ref))
    else:
        print("MISS 0x%08x : %s" % (a, ref))

# Decompile the coupling writer to confirm spec04 13.6 (mask &3, single write to 0x22, no strobe).
print("\n=== decompile FUN_001ae850 (coupling writer) ===")
di = DecompInterface()
di.openProgram(currentProgram)
f = fm.getFunctionContaining(af.getAddress(0x1ae850))
if f:
    res = di.decompileFunction(f, 60, monitor)
    if res and res.decompileCompleted():
        print(res.getDecompiledFunction().getC())
    else:
        print("decompile failed")
