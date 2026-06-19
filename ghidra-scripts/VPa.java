import ghidra.app.script.GhidraScript;
import ghidra.app.decompiler.*;
import ghidra.program.model.address.AddressSpace;
import ghidra.program.model.listing.*;
import java.io.*;
public class VPa extends GhidraScript {
    @Override public void run() throws Exception {
        AddressSpace sp = currentProgram.getAddressFactory().getDefaultAddressSpace();
        FunctionManager fm = currentProgram.getFunctionManager();
        DecompInterface di = new DecompInterface(); di.openProgram(currentProgram);
        String out = getScriptArgs().length>0?getScriptArgs()[0]:"/tmp/vpa.txt";
        PrintWriter w = new PrintWriter(new FileWriter(out));
        Function f = fm.getFunctionContaining(sp.getAddress(0x002300c8L));
        if(f!=null){ DecompileResults r=di.decompileFunction(f,90,monitor); if(r!=null&&r.decompileCompleted()) w.println(r.getDecompiledFunction().getC()); else w.println("//fail"); }
        else w.println("// no func");
        w.close(); println("wrote "+out);
    }
}
