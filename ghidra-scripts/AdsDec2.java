import ghidra.app.script.GhidraScript;
import ghidra.app.decompiler.*;
import ghidra.program.model.address.*;
import ghidra.program.model.listing.*;
import ghidra.program.model.mem.*;
import java.io.*;
public class AdsDec2 extends GhidraScript {
  public void run() throws Exception {
    String out=getScriptArgs().length>0?getScriptArgs()[0]:"/tmp/adsdec2.txt";
    PrintWriter pw=new PrintWriter(new FileWriter(out));
    AddressFactory af=currentProgram.getAddressFactory();
    FunctionManager fm=currentProgram.getFunctionManager();
    DecompInterface di=new DecompInterface(); di.openProgram(currentProgram);
    for(long x:new long[]{0x00012e0cL,0x0003f8a8L,0x00014b3cL}){
      Address ad=af.getDefaultAddressSpace().getAddress(x);
      Function f=fm.getFunctionContaining(ad);
      if(f==null){pw.println("== no func @ "+Long.toHexString(x));continue;}
      pw.println("==== "+f.getName()+" @ "+f.getEntryPoint()+" ====");
      DecompileResults dr=di.decompileFunction(f,90,monitor);
      if(dr!=null&&dr.getDecompiledFunction()!=null)pw.println(dr.getDecompiledFunction().getC());
    }
    // dump the 8-byte magic at DAT_0003f8a4 target
    pw.close();
  }
}
