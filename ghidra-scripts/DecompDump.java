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

public class DecompDump extends GhidraScript {
    @Override
    public void run() throws Exception {
        long[] addrs = {
            0x000cc184L, 0x000cc224L, 0x001b3500L,            // register primitives (write/read/PLANE-A)
            0x000cc628L, 0x001bba20L, 0x001b0dc4L, 0x000ce2f0L, // bitstream load (entry -> loader -> SPI)
            0x001ae530L, 0x0021371cL, 0x001b05c8L, 0x001b0570L, // enable 0x44 / run 0x35 / divisor 0x19-0x1b/0x36
            0x001b07dcL, 0x001b083cL,                          // arm (0xC0/0x57/0xC3) / latch (0xC8)
            0x000d3148L, 0x001b06ccL, 0x001b04e4L,             // dispatcher / status 0x38 bit0 / 0x39 done
            0x001aef60L, 0x001af1fcL,                          // roll ADC 0x41-0x59 / deep drain 0x30-0x34
            0x001ae850L, 0x00075ad4L, 0x001adbccL,             // coupling 0x22 / offset+cal formula / offset DAC
        };
        String[] labels = {
            "FUN_000cc184 PLANE-A byte writer (strb#1=CS1)", "FUN_000cc224 GPMC read primitive", "FUN_001b3500 PLANE-A write wrapper",
            "FUN_000cc628 bitstream-load entry", "FUN_001bba20 bitstream load", "FUN_001b0dc4 bit-clocking loader", "FUN_000ce2f0 SPI xfer",
            "FUN_001ae530 0x44 enable strobe", "FUN_0021371c 0x35 run/mode writer", "FUN_001b05c8 divisor class mapper", "FUN_001b0570 rt-mode divisor 0x36",
            "FUN_001b07dc arm (0xC0/0x57/0xC3)", "FUN_001b083c stop/latch 0xC8",
            "FUN_000d3148 per-tick dispatcher", "FUN_001b06cc status 0x38 bit0", "FUN_001b04e4 0x39 done",
            "FUN_001aef60 roll ADC 0x41/0x59", "FUN_001af1fc deep-frame drain 0x30-0x34",
            "FUN_001ae850 coupling 0x22", "FUN_00075ad4 offset/cal volts->code", "FUN_001adbcc offset-DAC fanout",
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
