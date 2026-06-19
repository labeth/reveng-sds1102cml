import ghidra.app.script.GhidraScript;
import ghidra.program.model.address.*;
import ghidra.program.model.listing.*;

// Args: <addrHex,addrHex,...> -- print the 32-bit pointer stored at each addr,
// and the function/symbol it points to (if any). Prints to console.
public class PtrDump extends GhidraScript {
  public void run() throws Exception {
    String[] a = getScriptArgs();
    String[] addrs = a.length>0 ? a[0].split(",") : new String[0];
    AddressFactory af = currentProgram.getAddressFactory();
    FunctionManager fm = currentProgram.getFunctionManager();
    Listing lst = currentProgram.getListing();
    for (String s : addrs) {
      long x = Long.parseLong(s.trim().replace("0x",""),16);
      Address ad = af.getDefaultAddressSpace().getAddress(x);
      try {
        long v = getInt(ad) & 0xffffffffL;
        Address tv = af.getDefaultAddressSpace().getAddress(v);
        Function f = fm.getFunctionContaining(tv);
        Data d = lst.getDefinedDataContaining(tv);
        String drep = d!=null ? d.getDefaultValueRepresentation() : null;
        println(String.format("@0x%x -> 0x%x  func=%s  data=%s", x, v,
          f!=null?(f.getName()+"@"+f.getEntryPoint()):"-",
          drep!=null?drep:"-"));
      } catch (Exception e) { println("@0x"+Long.toHexString(x)+" ERR "+e); }
    }
  }
}
