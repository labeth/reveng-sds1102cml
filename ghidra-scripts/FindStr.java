import ghidra.app.script.GhidraScript;
import ghidra.program.model.address.*;
import ghidra.program.model.listing.*;
import ghidra.program.model.mem.*;
import ghidra.program.model.symbol.*;
import ghidra.program.util.*;
import java.io.*;
import java.util.*;

// Args: <outfile> <needle1|needle2|...>
// Find defined-data/string occurrences containing each needle, print address +
// the value, and list functions that reference that address (callers).
public class FindStr extends GhidraScript {
  public void run() throws Exception {
    String[] a = getScriptArgs();
    String out = a.length>0 ? a[0] : "/tmp/findstr.txt";
    String[] needles = a.length>1 ? a[1].split("\\|") : new String[]{"svc_register"};
    PrintWriter pw = new PrintWriter(new FileWriter(out));
    Listing lst = currentProgram.getListing();
    ReferenceManager rm = currentProgram.getReferenceManager();
    FunctionManager fm = currentProgram.getFunctionManager();
    DataIterator di = lst.getDefinedData(true);
    int count=0;
    while (di.hasNext()) {
      Data d = di.next();
      String v = d.getDefaultValueRepresentation();
      if (v == null) continue;
      for (String n : needles) {
        if (v.contains(n)) {
          pw.println("STR @" + d.getAddress() + " = " + v);
          ReferenceIterator it = rm.getReferencesTo(d.getAddress());
          while (it.hasNext()) {
            Reference r = it.next();
            Function f = fm.getFunctionContaining(r.getFromAddress());
            pw.println("    <- " + r.getFromAddress() + (f!=null?("  in "+f.getName()+" @"+f.getEntryPoint()):"  (no func)"));
          }
          count++;
          break;
        }
      }
    }
    pw.println("// total matches: " + count);
    pw.close();
    println("wrote " + out + " matches=" + count);
  }
}
