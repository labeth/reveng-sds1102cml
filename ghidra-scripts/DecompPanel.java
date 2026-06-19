import ghidra.app.script.GhidraScript;
import ghidra.app.decompiler.DecompInterface;
import ghidra.app.decompiler.DecompileResults;
import ghidra.program.model.address.AddressSpace;
import ghidra.program.model.listing.Function;
import ghidra.program.model.listing.FunctionManager;
import java.io.FileWriter;
import java.io.PrintWriter;
public class DecompPanel extends GhidraScript {
    @Override public void run() throws Exception {
        long[] addrs = { 0x000b6080L, 0x000b65b4L, 0x001b1bb0L, 0x000ce2f0L };
        String[] labels = { "SIGIO key handler @b6080", "FUN_000b65b4 adjust-encoder region", "FUN_001b1bb0 beeper init wrapper", "ce2f0" };
        AddressSpace sp = currentProgram.getAddressFactory().getDefaultAddressSpace();
        FunctionManager fm = currentProgram.getFunctionManager();
        DecompInterface di = new DecompInterface();
        di.openProgram(currentProgram);
        String out = getScriptArgs().length>0?getScriptArgs()[0]:"/tmp/decomp.txt";
        PrintWriter w = new PrintWriter(new FileWriter(out));
        for (int i=0;i<addrs.length;i++){
            w.println("// ===== "+labels[i]+" @0x"+Long.toHexString(addrs[i])+" =====");
            Function fn=fm.getFunctionContaining(sp.getAddress(addrs[i]));
            if(fn==null){w.println("// (no function)\n");continue;}
            DecompileResults r=di.decompileFunction(fn,90,monitor);
            if(r!=null&&r.decompileCompleted()) w.println(r.getDecompiledFunction().getC());
            else w.println("// decompile failed");
            w.println();
        }
        w.close(); println("wrote "+out);
    }
}
