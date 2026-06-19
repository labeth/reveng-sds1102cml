import ghidra.app.script.GhidraScript;
import ghidra.app.decompiler.*;
import ghidra.program.model.address.*;
import ghidra.program.model.listing.*;
import java.io.*;

// Args: <outfile> <addrHex,addrHex,...> -- decompile each containing function.
public class Dec extends GhidraScript {
  public void run() throws Exception {
    String[] a = getScriptArgs();
    String out = a.length>0 ? a[0] : "/tmp/dec.txt";
    String[] addrs = a.length>1 ? a[1].split(",") : new String[0];
    PrintWriter pw = new PrintWriter(new FileWriter(out));
    AddressFactory af = currentProgram.getAddressFactory();
    FunctionManager fm = currentProgram.getFunctionManager();
    DecompInterface di = new DecompInterface(); di.openProgram(currentProgram);
    for (String s : addrs) {
      long x = Long.parseLong(s.trim().replace("0x",""),16);
      Address ad = af.getDefaultAddressSpace().getAddress(x);
      Function f = fm.getFunctionContaining(ad);
      if (f==null){ pw.println("// no func @0x"+Long.toHexString(x)); continue; }
      pw.println("// ===== " + f.getName() + " @ " + f.getEntryPoint() + " =====");
      DecompileResults dr = di.decompileFunction(f, 90, monitor);
      if (dr!=null && dr.getDecompiledFunction()!=null) pw.println(dr.getDecompiledFunction().getC());
      else pw.println("// decompile failed");
      pw.println();
    }
    pw.close();
    println("wrote " + out);
  }
}
