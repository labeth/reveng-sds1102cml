// Ghidra (Java) headless script: validate that the open-repo spec's FUN_ addresses
// map to real functions in SDS1000_arm.app (md5 e1bd88fb, image base 0x8000), and
// decompile one to confirm it matches the spec text. Run:
//   analyzeHeadless ~/ghidra-projects SDS1102 -process SDS1000_arm.app \
//       -scriptPath <this dir> -postScript ValidateSpecAddrs.java -noanalysis
import ghidra.app.script.GhidraScript;
import ghidra.app.decompiler.DecompInterface;
import ghidra.app.decompiler.DecompileResults;
import ghidra.program.model.address.Address;
import ghidra.program.model.address.AddressSpace;
import ghidra.program.model.listing.Function;
import ghidra.program.model.listing.FunctionManager;

public class ValidateSpecAddrs extends GhidraScript {
    @Override
    public void run() throws Exception {
        FunctionManager fm = currentProgram.getFunctionManager();
        AddressSpace sp = currentProgram.getAddressFactory().getDefaultAddressSpace();
        println("=== FUNC_COUNT " + fm.getFunctionCount() + " ===");

        long[] addrs = {0xcc224L, 0xcc184L, 0x1ae850L, 0x1b05c8L, 0x1ae530L, 0x21371cL, 0x1b2998L, 0x74fd4L};
        String[] refs = {
            "FUN_000cc224 GPMC read primitive (spec04 AppxA)",
            "FUN_000cc184 PLANE-A byte writer strb#1 (spec04 AppxA)",
            "FUN_001ae850 coupling writer 0x22 &3 (spec04 13.6)",
            "FUN_001b05c8 divisor class mapper (spec04 5.4)",
            "FUN_001ae530 0x44 enable strobe (spec04 5)",
            "FUN_0021371c 0x35 run/mode writer (spec04 5)",
            "FUN_001b2998 front-end relay assembler (spec06 8)",
            "FUN_00074fd4 calibration.dat reader 0xac0 (spec07 2.1)",
        };
        for (int i = 0; i < addrs.length; i++) {
            Address a = sp.getAddress(addrs[i]);
            Function f = fm.getFunctionContaining(a);
            if (f != null) {
                println(String.format("OK   0x%08x -> %s entry=0x%x size=%d : %s",
                        addrs[i], f.getName(), f.getEntryPoint().getOffset(),
                        f.getBody().getNumAddresses(), refs[i]));
            } else {
                println(String.format("MISS 0x%08x : %s", addrs[i], refs[i]));
            }
        }

        println("\n=== decompile FUN_001ae850 (coupling writer; spec04 13.6 expects AND #3 then write sel 0x22) ===");
        DecompInterface di = new DecompInterface();
        di.openProgram(currentProgram);
        Function f = fm.getFunctionContaining(sp.getAddress(0x1ae850L));
        if (f != null) {
            DecompileResults res = di.decompileFunction(f, 60, monitor);
            if (res != null && res.decompileCompleted()) {
                println(res.getDecompiledFunction().getC());
            } else {
                println("decompile failed");
            }
        }
    }
}
