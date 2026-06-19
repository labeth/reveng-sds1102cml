import ghidra.app.script.GhidraScript;
import ghidra.program.model.address.AddressSpace;
import ghidra.program.model.mem.Memory;
import java.io.*;
public class VP5 extends GhidraScript {
    String rd(Memory mem, AddressSpace sp, long ptr) throws Exception {
        int p = mem.getInt(sp.getAddress(ptr));
        StringBuilder s = new StringBuilder();
        for(int i=0;i<200;i++){ byte b=mem.getByte(sp.getAddress((p&0xffffffffL)+i)); if(b==0)break; s.append((char)(b&0xff)); }
        return s.toString();
    }
    @Override public void run() throws Exception {
        AddressSpace sp = currentProgram.getAddressFactory().getDefaultAddressSpace();
        Memory mem = currentProgram.getMemory();
        String out = getScriptArgs().length>0?getScriptArgs()[0]:"/tmp/vp5.txt";
        PrintWriter w = new PrintWriter(new FileWriter(out));
        // beeper init strings, ON, OFF
        long[] ptrs = {0x1b2418L,0x1b241cL,0x1b2420L, 0x1b24ccL, 0x230080L,
                       0x1ada1cL,0x1ada20L,0x1ada24L, 0x1adaa4L,0x1adaa8L,
                       0x000ce608L,0x000ce634L, 0x27e700L,0x27e710L};
        String[] lbl = {"beep init1","beep init2","beep init3","beep ON run","beep OFF run",
                        "gpio7 export","gpio7 dir","gpio7 val-init","gpio7 HIGH","gpio7 LOW",
                        "gpio113 clear","gpio113 set","keydev path","keydev errstr"};
        for(int i=0;i<ptrs.length;i++){ try{ w.println("// "+lbl[i]+" @0x"+Long.toHexString(ptrs[i])+" -> \""+rd(mem,sp,ptrs[i])+"\""); }catch(Exception e){ w.println("// "+lbl[i]+" err "+e); } }
        w.close(); println("wrote "+out);
    }
}
