import ghidra.app.script.GhidraScript;
import ghidra.program.model.address.*;
import ghidra.program.model.listing.*;
import ghidra.program.model.symbol.*;

// Args: <addrHex,addrHex,...> -- for each data address, list every reference
// to it (read/write/data) with the containing function. Prints to console.
public class Refs extends GhidraScript {
  public void run() throws Exception {
    String[] a = getScriptArgs();
    String[] addrs = a.length>0 ? a[0].split(",") : new String[0];
    AddressFactory af = currentProgram.getAddressFactory();
    FunctionManager fm = currentProgram.getFunctionManager();
    ReferenceManager rm = currentProgram.getReferenceManager();
    for (String s : addrs) {
      long x = Long.parseLong(s.trim().replace("0x",""),16);
      Address ad = af.getDefaultAddressSpace().getAddress(x);
      println("==== REFS TO 0x"+Long.toHexString(x)+" ====");
      ReferenceIterator it = rm.getReferencesTo(ad);
      boolean any=false;
      while (it.hasNext()) {
        any=true;
        Reference r = it.next();
        Address from = r.getFromAddress();
        Function f = fm.getFunctionContaining(from);
        println(String.format("  from 0x%s  %s  func=%s", from, r.getReferenceType(),
          f!=null?(f.getName()+"@"+f.getEntryPoint()):"-"));
      }
      if(!any) println("  (none)");
    }
  }
}
