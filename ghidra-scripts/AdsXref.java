import ghidra.app.script.GhidraScript;
import ghidra.app.decompiler.*;
import ghidra.program.model.address.*;
import ghidra.program.model.listing.*;
import ghidra.program.model.symbol.*;
import java.io.*;
public class AdsXref extends GhidraScript {
  public void run() throws Exception {
    String out = getScriptArgs().length>0?getScriptArgs()[0]:"/tmp/ads.txt";
    PrintWriter pw=new PrintWriter(new FileWriter(out));
    AddressFactory af=currentProgram.getAddressFactory();
    FunctionManager fm=currentProgram.getFunctionManager();
    DecompInterface di=new DecompInterface(); di.openProgram(currentProgram);
    ReferenceManager rm=currentProgram.getReferenceManager();
    // string vaddrs to trace
    long[] strs={0x278ee8L,0x278e84L,0x2788b8L,0x279e74L};
    java.util.Set<Function> seen=new java.util.HashSet<>();
    for(long s: strs){
      Address sa=af.getDefaultAddressSpace().getAddress(s);
      ReferenceIterator it=rm.getReferencesTo(sa);
      while(it.hasNext()){
        Reference r=it.next();
        Function f=fm.getFunctionContaining(r.getFromAddress());
        if(f!=null && seen.add(f)){
          pw.println("==== "+f.getName()+" @ "+f.getEntryPoint()+" (ref to "+Long.toHexString(s)+") ====");
          DecompileResults dr=di.decompileFunction(f,60,monitor);
          if(dr!=null && dr.getDecompiledFunction()!=null) pw.println(dr.getDecompiledFunction().getC());
        }
      }
    }
    pw.close();
  }
}
