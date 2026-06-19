import ghidra.app.script.GhidraScript;
import ghidra.app.decompiler.*;
import ghidra.program.model.address.AddressSpace;
import ghidra.program.model.listing.*;
import java.io.*;
public class VP3 extends GhidraScript {
    @Override public void run() throws Exception {
        long[] addrs = { 0x000ceac0L };
        AddressSpace sp = currentProgram.getAddressFactory().getDefaultAddressSpace();
        FunctionManager fm = currentProgram.getFunctionManager();
        DecompInterface di = new DecompInterface(); di.openProgram(currentProgram);
        String out = getScriptArgs().length>0?getScriptArgs()[0]:"/tmp/vp3.txt";
        PrintWriter w = new PrintWriter(new FileWriter(out));
        for (long a: addrs){
            w.println("// ===== @0x"+Long.toHexString(a)+" =====");
            Function f = fm.getFunctionContaining(sp.getAddress(a));
            if(f==null){w.println("// none\n");continue;}
            DecompileResults r = di.decompileFunction(f,90,monitor);
            if(r!=null&&r.decompileCompleted()) w.println(r.getDecompiledFunction().getC()); else w.println("// fail");
            w.println();
        }
        w.close(); println("wrote "+out);
    }
}
