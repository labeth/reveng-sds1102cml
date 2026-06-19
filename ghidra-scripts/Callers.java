import ghidra.app.script.GhidraScript;
import ghidra.app.decompiler.*;
import ghidra.program.model.address.*;
import ghidra.program.model.listing.*;
import ghidra.program.model.symbol.*;
import java.io.*;
import java.util.*;

// Args: <outfile> <targetAddrHex,targetAddrHex,...>
// For each target function address, find every function that references it
// (callers), and decompile each caller. Also decompile the targets themselves.
public class Callers extends GhidraScript {
  public void run() throws Exception {
    String[] a = getScriptArgs();
    String out = a.length>0 ? a[0] : "/tmp/callers.txt";
    String[] targs = a.length>1 ? a[1].split(",") : new String[0];
    PrintWriter pw = new PrintWriter(new FileWriter(out));
    AddressFactory af = currentProgram.getAddressFactory();
    FunctionManager fm = currentProgram.getFunctionManager();
    DecompInterface di = new DecompInterface(); di.openProgram(currentProgram);
    ReferenceManager rm = currentProgram.getReferenceManager();
    Set<String> seen = new HashSet<>();
    for (String ts : targs) {
      long t = Long.parseLong(ts.trim().replace("0x",""), 16);
      Address ta = af.getDefaultAddressSpace().getAddress(t);
      Function tf = fm.getFunctionContaining(ta);
      String tn = tf!=null ? tf.getName() : ("0x"+Long.toHexString(t));
      pw.println("################ CALLERS OF " + tn + " @0x" + Long.toHexString(t) + " ################");
      Address entry = tf!=null ? tf.getEntryPoint() : ta;
      ReferenceIterator it = rm.getReferencesTo(entry);
      List<Function> callers = new ArrayList<>();
      while (it.hasNext()) {
        Reference r = it.next();
        Function f = fm.getFunctionContaining(r.getFromAddress());
        if (f != null && !callers.contains(f)) callers.add(f);
      }
      if (callers.isEmpty()) pw.println("// (no callers found via xref)");
      for (Function f : callers) {
        String key = f.getEntryPoint().toString();
        pw.println("==== CALLER " + f.getName() + " @ " + f.getEntryPoint() + "  -> " + tn + " ====");
        if (seen.add(key)) {
          DecompileResults dr = di.decompileFunction(f, 90, monitor);
          if (dr!=null && dr.getDecompiledFunction()!=null) pw.println(dr.getDecompiledFunction().getC());
          else pw.println("// decompile failed");
        } else {
          pw.println("// (decompiled above)");
        }
      }
      pw.println();
    }
    pw.close();
    println("wrote " + out);
  }
}
