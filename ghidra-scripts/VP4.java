import ghidra.app.script.GhidraScript;
import ghidra.program.model.address.AddressSpace;
import ghidra.program.model.mem.Memory;
import java.io.*;
public class VP4 extends GhidraScript {
    @Override public void run() throws Exception {
        AddressSpace sp = currentProgram.getAddressFactory().getDefaultAddressSpace();
        Memory mem = currentProgram.getMemory();
        String out = getScriptArgs().length>0?getScriptArgs()[0]:"/tmp/vp4.txt";
        PrintWriter w = new PrintWriter(new FileWriter(out));
        long[] dats = {0x000ceba8L, 0x001b24c8L, 0x001b24d0L};
        for(long d: dats){ try{int v=mem.getInt(sp.getAddress(d)); w.println("// DAT_"+Long.toHexString(d)+" = 0x"+Integer.toHexString(v)+" ("+v+")");}catch(Exception e){w.println("// "+Long.toHexString(d)+" unreadable");}}
        w.close(); println("wrote "+out);
    }
}
