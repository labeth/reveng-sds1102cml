// Ghidra (Java) headless: decompile a curated set of the vendor app's FPGA bring-up
// + acquisition-drive functions (spec 04 Appendix A) to a file, as an authoritative
// reference to cross-check the runtime reglog and the sim against. Run:
//   analyzeHeadless ~/ghidra-projects SDS1102 -process SDS1000_arm.app \
//     -scriptPath <dir> -postScript DecompDump.java <output-file> -noanalysis
import ghidra.app.script.GhidraScript;
import ghidra.app.decompiler.DecompInterface;
import ghidra.app.decompiler.DecompileResults;
import ghidra.program.model.address.AddressSpace;
import ghidra.program.model.listing.Function;
import ghidra.program.model.listing.FunctionManager;
import java.io.FileWriter;
import java.io.PrintWriter;

public class DecompDump06 extends GhidraScript {
    @Override
    public void run() throws Exception {
        long[] addrs = {
            0x001b32c0L, 0x001add80L, 0x000cba50L, 0x00076440L, 0x001b1b54L,
            0x001adbccL, 0x001adfdcL, 0x000ce23cL,
        };
        String[] labels = {
            "FUN_001b32c0 per-bit relay switch", "FUN_001add80 per-ch relay helper", "FUN_000cba50 ch-state probe", "FUN_00076440 gain DAC fanout", "FUN_001b1b54 2-byte spidev1.1 flush",
            "FUN_001adbcc offset-DAC fanout", "FUN_001adfdc PLANE-B writer", "FUN_000ce23c spidev1.1 8-bit writer",
        };
        AddressSpace sp = currentProgram.getAddressFactory().getDefaultAddressSpace();
        FunctionManager fm = currentProgram.getFunctionManager();
        DecompInterface di = new DecompInterface();
        di.openProgram(currentProgram);
        String out = getScriptArgs().length > 0 ? getScriptArgs()[0] : "/tmp/decomp.txt";
        PrintWriter w = new PrintWriter(new FileWriter(out));
        w.println("// Decompiled FPGA bring-up + acquisition-drive functions of SDS1000_arm.app");
        w.println("// (md5 e1bd88fb, image base 0x8000). Ghidra 12.1.2 ARM:LE:32:v8. Reference for");
        w.println("// validating the runtime reglog + sim/fpga against specs/04.\n");
        for (int i = 0; i < addrs.length; i++) {
            w.println("// ===== " + labels[i] + " @0x" + Long.toHexString(addrs[i]) + " =====");
            Function f = fm.getFunctionContaining(sp.getAddress(addrs[i]));
            if (f == null) { w.println("// (no function at this address)\n"); continue; }
            DecompileResults r = di.decompileFunction(f, 60, monitor);
            if (r != null && r.decompileCompleted()) w.println(r.getDecompiledFunction().getC());
            else w.println("// decompile failed");
            w.println();
        }
        w.close();
        println("wrote " + out);
    }
}
