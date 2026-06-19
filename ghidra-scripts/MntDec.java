import ghidra.app.script.GhidraScript;
import ghidra.app.decompiler.*;
import ghidra.program.model.address.*;
import ghidra.program.model.listing.*;
import java.io.*;
public class MntDec extends GhidraScript {
  public void run() throws Exception {
    PrintWriter pw=new PrintWriter(new FileWriter(getScriptArgs()[0]));
    AddressFactory af=currentProgram.getAddressFactory();
    FunctionManager fm=currentProgram.getFunctionManager();
    DecompInterface di=new DecompInterface(); di.openProgram(currentProgram);
    // mount string consumers near literal pool; find functions containing code that references vfat va 0x278458
    long[] strs={0x278458L,0x27844cL,0x27a6f8L,0x278654L,0x2784fcL};
    java.util.Set<Function> seen=new java.util.HashSet<>();
    var rm=currentProgram.getReferenceManager();
    for(long s:strs){
      Address sa=af.getDefaultAddressSpace().getAddress(s);
      var it=rm.getReferencesTo(sa);
      while(it.hasNext()){
        var r=it.next();
        Function f=fm.getFunctionContaining(r.getFromAddress());
        if(f!=null&&seen.add(f)){
          pw.println("==== "+f.getName()+" @ "+f.getEntryPoint()+" (->"+Long.toHexString(s)+") ====");
          var dr=di.decompileFunction(f,90,monitor);
          if(dr!=null&&dr.getDecompiledFunction()!=null)pw.println(dr.getDecompiledFunction().getC());
        }
      }
    }
    pw.close();
  }
}
