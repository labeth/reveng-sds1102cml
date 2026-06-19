import ghidra.app.script.GhidraScript;
import ghidra.app.decompiler.*;
import ghidra.program.model.address.AddressSpace;
import ghidra.program.model.listing.*;
import java.io.*;
public class S08c extends GhidraScript {
  public void run() throws Exception {
    long[] a={0x0003e138L,0x001ea238L,0x0003e360L};
    AddressSpace sp=currentProgram.getAddressFactory().getDefaultAddressSpace();
    FunctionManager fm=currentProgram.getFunctionManager();
    DecompInterface di=new DecompInterface(); di.openProgram(currentProgram);
    PrintWriter w=new PrintWriter(new FileWriter(getScriptArgs()[0]));
    for(long ad:a){ w.println("// ==== @0x"+Long.toHexString(ad)+" ====");
      Function f=fm.getFunctionContaining(sp.getAddress(ad));
      if(f==null){w.println("none\n");continue;}
      DecompileResults r=di.decompileFunction(f,90,monitor);
      w.println(r!=null&&r.decompileCompleted()?r.getDecompiledFunction().getC():"fail"); w.println();}
    w.close(); println("ok");
  }
}
