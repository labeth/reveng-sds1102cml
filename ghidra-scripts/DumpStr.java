import ghidra.app.script.GhidraScript;
import ghidra.program.model.address.Address;
public class DumpStr extends GhidraScript {
  String readStr(long ptrAddr){
    try{ Address p=toAddr(ptrAddr); long target=getInt(p)&0xffffffffL;
      Address s=toAddr(target); StringBuilder sb=new StringBuilder();
      for(int i=0;i<120;i++){ byte b=getByte(s.add(i)); if(b==0)break; sb.append((char)(b&0xff)); }
      return String.format("@%x->%08x: \"%s\"",ptrAddr,target,sb.toString());
    }catch(Exception e){return "@"+Long.toHexString(ptrAddr)+" err "+e;}
  }
  @Override public void run() throws Exception {
    long[] a={0x1b2418L,0x1b241cL,0x1b2420L,0x1b24ccL,0x1b24c8L};
    for(long x:a) println(readStr(x));
    // 0x1b24c8 is an int literal not a string ptr:
    try{ println("DAT_001b24c8 int = "+(getInt(toAddr(0x1b24c8L))&0xffffffffL)); }catch(Exception e){}
  }
}
