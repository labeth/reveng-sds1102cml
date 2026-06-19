import ghidra.app.script.GhidraScript;
import ghidra.program.model.address.AddressSpace;
import ghidra.program.model.mem.Memory;
import java.io.*;
public class VP6 extends GhidraScript {
    String rdat(Memory mem, AddressSpace sp, long a) throws Exception {
        StringBuilder s=new StringBuilder();
        for(int i=0;i<120;i++){ byte b=mem.getByte(sp.getAddress(a+i)); if(b==0)break; s.append((char)(b&0xff)); }
        return s.toString();
    }
    @Override public void run() throws Exception {
        AddressSpace sp = currentProgram.getAddressFactory().getDefaultAddressSpace();
        Memory mem = currentProgram.getMemory();
        String out = getScriptArgs().length>0?getScriptArgs()[0]:"/tmp/vp6.txt";
        PrintWriter w = new PrintWriter(new FileWriter(out));
        long[] a = {0x27e700L,0x27e710L,0x284560L,0x293278L};
        String[] l = {"keydev path","open err str","keyboard test UI","keyboard.dat path"};
        for(int i=0;i<a.length;i++){ try{ w.println("// "+l[i]+" @0x"+Long.toHexString(a[i])+" -> \""+rdat(mem,sp,a[i])+"\""); }catch(Exception e){ w.println("// "+l[i]+" err"); } }
        w.close(); println("wrote "+out);
    }
}
