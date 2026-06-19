import ghidra.app.script.GhidraScript;
import ghidra.program.model.address.Address;
public class DumpIoctl extends GhidraScript {
  long rd(long p){ try{return getInt(toAddr(p))&0xffffffffL;}catch(Exception e){return -1;} }
  @Override public void run() throws Exception {
    long[] a={0xcdf24L,0xcdf28L,0xcdf2cL,0xcdf30L,0xcdf34L,0xcdf38L,0xcdf3cL,0xcdf40L,0xcdf44L};
    String[] n={"DAT_cdf24(speed val)","DAT_cdf28(path ptr)","DAT_cdf2c(fd ptr)","DAT_cdf30(ioctl1)","DAT_cdf34(ioctl2)","DAT_cdf38(ioctl3)","DAT_cdf3c(ioctl4)","DAT_cdf40(ioctl5)","DAT_cdf44(ioctl6)"};
    for(int i=0;i<a.length;i++){ long v=rd(a[i]); println(String.format("%s = 0x%08x",n[i],v)); }
    // path string
    try{ long t=rd(0xcdf28L); Address s=toAddr(t); StringBuilder sb=new StringBuilder();
      for(int i=0;i<60;i++){byte b=getByte(s.add(i)); if(b==0)break; sb.append((char)(b&0xff));}
      println("path = \""+sb+"\""); }catch(Exception e){}
  }
}
