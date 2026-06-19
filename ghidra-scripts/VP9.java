import ghidra.app.script.GhidraScript;
import ghidra.app.decompiler.*;
import ghidra.program.model.address.*;
import ghidra.program.model.symbol.*;
import ghidra.program.model.listing.*;
import java.io.*;
public class VP9 extends GhidraScript {
    @Override public void run() throws Exception {
        AddressSpace sp = currentProgram.getAddressFactory().getDefaultAddressSpace();
        ReferenceManager rm = currentProgram.getReferenceManager();
        ReferenceIterator it = rm.getReferencesTo(sp.getAddress(0x0023005cL));
        String out = getScriptArgs().length>0?getScriptArgs()[0]:"/tmp/vp9.txt";
        PrintWriter w = new PrintWriter(new FileWriter(out));
        w.println("// refs to FUN_0023005c (beep OFF):");
        while(it.hasNext()){ Reference r=it.next(); w.println("//   "+r.getFromAddress()+" "+r.getReferenceType()); }
        // find signal() calls with arg 14 (SIGALRM) - search for setitimer caller context: just dump function containing 23005c refs
        w.close(); println("wrote "+out);
    }
}
