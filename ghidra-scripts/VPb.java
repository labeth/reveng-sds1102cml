import ghidra.app.script.GhidraScript;
import ghidra.program.model.address.AddressSpace;
import ghidra.program.model.mem.Memory;
import java.io.*;
public class VPb extends GhidraScript {
    @Override public void run() throws Exception {
        AddressSpace sp = currentProgram.getAddressFactory().getDefaultAddressSpace();
        Memory mem = currentProgram.getMemory();
        String out = getScriptArgs().length>0?getScriptArgs()[0]:"/tmp/vpb.txt";
        PrintWriter w = new PrintWriter(new FileWriter(out));
        int v = mem.getInt(sp.getAddress(0x0023028cL));
        w.println("// DAT_23028c (SIGALRM handler) = 0x"+Integer.toHexString(v));
        w.close(); println("ok");
    }
}
