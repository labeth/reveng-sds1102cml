import ghidra.app.script.GhidraScript;
import ghidra.program.model.address.Address;
public class DumpStr2 extends GhidraScript {
  String readStr(long ptrAddr){
    try{ Address p=toAddr(ptrAddr); long t=getInt(p)&0xffffffffL; Address s=toAddr(t);
      StringBuilder sb=new StringBuilder();
      for(int i=0;i<120;i++){ byte b=getByte(s.add(i)); if(b==0)break; sb.append((char)(b&0xff)); }
      return String.format("@%x->%08x: \"%s\"",ptrAddr,t,sb.toString());
    }catch(Exception e){return "@"+Long.toHexString(ptrAddr)+" err";}
  }
  @Override public void run() throws Exception {
    long[] a={0xce608L,0xce634L};  // gpio113 clear / set
    for(long x:a) println(readStr(x));
  }
}
