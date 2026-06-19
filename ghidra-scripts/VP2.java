import ghidra.app.script.GhidraScript;
import ghidra.app.decompiler.DecompInterface;
import ghidra.app.decompiler.DecompileResults;
import ghidra.program.model.address.AddressSpace;
import ghidra.program.model.listing.Function;
import ghidra.program.model.listing.FunctionManager;
import ghidra.program.model.mem.Memory;
import java.io.FileWriter;
import java.io.PrintWriter;
public class VP2 extends GhidraScript {
    @Override
    public void run() throws Exception {
        long[] addrs = { 0x001b3534L, 0x001b3500L, 0x000cebacL, 0x000cebe0L, 0x001ea124L };
        AddressSpace sp = currentProgram.getAddressFactory().getDefaultAddressSpace();
        FunctionManager fm = currentProgram.getFunctionManager();
        Memory mem = currentProgram.getMemory();
        DecompInterface di = new DecompInterface();
        di.openProgram(currentProgram);
        String out = getScriptArgs().length > 0 ? getScriptArgs()[0] : "/tmp/vp2.txt";
        PrintWriter w = new PrintWriter(new FileWriter(out));
        long[] dats = {0x000cc2bcL, 0x000cc220L, 0x000cbfa0L, 0x000cc21cL, 0x000cbf9cL};
        for (long d : dats) { try { int v=mem.getInt(sp.getAddress(d)); w.println("// DAT_"+Long.toHexString(d)+" = 0x"+Integer.toHexString(v)); } catch(Exception e){ w.println("// DAT_"+Long.toHexString(d)+" unreadable"); } }
        w.println();
        for (long a : addrs) {
            w.println("// ===== @0x"+Long.toHexString(a)+" =====");
            Function f = fm.getFunctionContaining(sp.getAddress(a));
            if (f==null){ w.println("// (none)\n"); continue; }
            DecompileResults r = di.decompileFunction(f,90,monitor);
            if (r!=null && r.decompileCompleted()) w.println(r.getDecompiledFunction().getC()); else w.println("// fail");
            w.println();
        }
        w.close(); println("wrote "+out);
    }
}
