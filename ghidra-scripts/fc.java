import ghidra.app.script.GhidraScript;
public class fc extends GhidraScript {
    @Override public void run() throws Exception {
        long[] a={0x2953b4L,0x32d944L,0x2956f4L,0x282c54L};
        for(long x:a){
          int iv=getInt(toAddr(x));
          float f=Float.intBitsToFloat(iv);
          println(String.format("@%x int=0x%08x float=%g",x,iv&0xffffffffL,f));
        }
    }
}
