import ghidra.app.script.GhidraScript;
import ghidra.program.model.address.*;
import ghidra.program.model.listing.*;

// Args: <startHex:count,...> -- disassemble count instructions from start. Console.
public class Dis extends GhidraScript {
  public void run() throws Exception {
    String[] a = getScriptArgs();
    String[] specs = a.length>0 ? a[0].split(",") : new String[0];
    AddressFactory af = currentProgram.getAddressFactory();
    Listing lst = currentProgram.getListing();
    for (String s : specs) {
      String[] p = s.split(":");
      long x = Long.parseLong(p[0].trim().replace("0x",""),16);
      int n = p.length>1 ? Integer.parseInt(p[1].trim()) : 12;
      Address ad = af.getDefaultAddressSpace().getAddress(x);
      println("---- DIS @0x"+Long.toHexString(x)+" ----");
      Instruction ins = lst.getInstructionAt(ad);
      for (int i=0;i<n && ins!=null;i++) {
        println(String.format("  0x%s  %s", ins.getAddress(), ins.toString()));
        ins = ins.getNext();
      }
    }
  }
}
