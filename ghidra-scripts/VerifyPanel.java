import ghidra.app.script.GhidraScript;
import ghidra.app.decompiler.DecompInterface;
import ghidra.app.decompiler.DecompileResults;
import ghidra.program.model.address.AddressSpace;
import ghidra.program.model.listing.Function;
import ghidra.program.model.listing.FunctionManager;
import ghidra.program.model.mem.Memory;
import java.io.FileWriter;
import java.io.PrintWriter;

public class VerifyPanel extends GhidraScript {
    @Override
    public void run() throws Exception {
        long[] addrs = {
            0x000b6080L, 0x000b603cL, 0x000cc224L, 0x000cc184L, 0x000cbf04L,
            0x001b2424L, 0x001ea124L, 0x001cd730L, 0x001cd770L, 0x001b23ecL,
            0x001ad9f0L, 0x001ada64L, 0x000ce5e0L, 0x000ce60cL,
            0x001bb688L, 0x001bb4b0L, 0x001bb604L, 0x00029ed4L,
        };
        AddressSpace sp = currentProgram.getAddressFactory().getDefaultAddressSpace();
        FunctionManager fm = currentProgram.getFunctionManager();
        Memory mem = currentProgram.getMemory();
        DecompInterface di = new DecompInterface();
        di.openProgram(currentProgram);
        String out = getScriptArgs().length > 0 ? getScriptArgs()[0] : "/tmp/vp.txt";
        PrintWriter w = new PrintWriter(new FileWriter(out));
        // dump DAT pointers used by signal/handler
        long[] dats = {0x000b669cL, 0x000b6690L, 0x000b6698L, 0x000b65a0L, 0x000b65a4L,
                       0x000b65a8L, 0x000b65acL, 0x000b65b4L, 0x000b65e0L, 0x000cc2c0L};
        for (long d : dats) {
            try {
                int v = mem.getInt(sp.getAddress(d));
                w.println("// DAT_" + Long.toHexString(d) + " = 0x" + Integer.toHexString(v));
            } catch (Exception e) { w.println("// DAT_" + Long.toHexString(d) + " unreadable"); }
        }
        w.println();
        for (long a : addrs) {
            w.println("// ===== @0x" + Long.toHexString(a) + " =====");
            Function f = fm.getFunctionContaining(sp.getAddress(a));
            if (f == null) { w.println("// (no function at this address)\n"); continue; }
            DecompileResults r = di.decompileFunction(f, 90, monitor);
            if (r != null && r.decompileCompleted()) w.println(r.getDecompiledFunction().getC());
            else w.println("// decompile failed");
            w.println();
        }
        w.close();
        println("wrote " + out);
    }
}
