import ghidra.app.script.GhidraScript;
import ghidra.app.decompiler.DecompInterface;
import ghidra.app.decompiler.DecompileResults;
import ghidra.program.model.address.AddressSpace;
import ghidra.program.model.listing.Function;
import ghidra.program.model.listing.FunctionManager;
import java.io.FileWriter;
import java.io.PrintWriter;

public class Spec08Dec extends GhidraScript {
    @Override
    public void run() throws Exception {
        long[] addrs = {
            0x0003ffe8L, 0x0003e3b0L, 0x00041e70L, 0x001ee0d0L,
            0x002300a4L, 0x0003de10L, 0x0004b9b8L, 0x000404a8L,
            0x00012fe4L, 0x0003f8a8L, 0x0003fe78L,
        };
        AddressSpace sp = currentProgram.getAddressFactory().getDefaultAddressSpace();
        FunctionManager fm = currentProgram.getFunctionManager();
        DecompInterface di = new DecompInterface();
        di.openProgram(currentProgram);
        String out = getScriptArgs().length > 0 ? getScriptArgs()[0] : "/tmp/spec08.txt";
        PrintWriter w = new PrintWriter(new FileWriter(out));
        for (int i = 0; i < addrs.length; i++) {
            w.println("// ===== @0x" + Long.toHexString(addrs[i]) + " =====");
            Function f = fm.getFunctionContaining(sp.getAddress(addrs[i]));
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
