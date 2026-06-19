import ghidra.app.script.GhidraScript;
import ghidra.app.decompiler.*;
import ghidra.program.model.address.*;
import ghidra.program.model.listing.*;
import java.io.*;
public class AdsDec extends GhidraScript {
  public void run() throws Exception {
    String out=getScriptArgs().length>0?getScriptArgs()[0]:"/tmp/adsdec.txt";
    PrintWriter pw=new PrintWriter(new FileWriter(out));
    AddressFactory af=currentProgram.getAddressFactory();
    FunctionManager fm=currentProgram.getFunctionManager();
    DecompInterface di=new DecompInterface(); di.openProgram(currentProgram);
    // addrs inline below

    for(long x:new long[]{0x00012fe4L,0x0003fcccL,0x0003f844L,0x0003fe78L,0x0003e3b0L}){
      Address ad=af.getDefaultAddressSpace().getAddress(x);
      Function f=fm.getFunctionContaining(ad);
      if(f==null){pw.println("== no func @ "+Long.toHexString(x));continue;}
      pw.println("==== "+f.getName()+" @ "+f.getEntryPoint()+" ====");
      DecompileResults dr=di.decompileFunction(f,60,monitor);
      if(dr!=null&&dr.getDecompiledFunction()!=null)pw.println(dr.getDecompiledFunction().getC());
    }
    pw.close();
  }
}
