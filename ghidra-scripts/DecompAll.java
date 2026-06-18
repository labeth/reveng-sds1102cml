// Ghidra (Java) headless: decompile every address listed (one hex addr per line) in
// the file given as arg[0], writing the C to arg[1]. Used to produce the complete
// decompiled reference of all FUN_ addresses the open specs cite. Run:
//   analyzeHeadless ~/ghidra-projects SDS1102 -process SDS1000_arm.app \
//     -scriptPath <dir> -postScript DecompAll.java <addr-list> <out-file> -noanalysis
import ghidra.app.script.GhidraScript;
import ghidra.app.decompiler.DecompInterface;
import ghidra.app.decompiler.DecompileResults;
import ghidra.program.model.address.AddressSpace;
import ghidra.program.model.listing.Function;
import ghidra.program.model.listing.FunctionManager;
import java.io.BufferedReader;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.PrintWriter;

public class DecompAll extends GhidraScript {
    @Override
    public void run() throws Exception {
        String[] args = getScriptArgs();
        BufferedReader r = new BufferedReader(new FileReader(args[0]));
        PrintWriter w = new PrintWriter(new FileWriter(args[1]));
        w.println("// Decompiled reference: every FUN_ address the open specs cite, from");
        w.println("// SDS1000_arm.app (md5 e1bd88fb, base 0x8000). Ghidra 12.1.2 ARM:LE:32:v8.\n");
        AddressSpace sp = currentProgram.getAddressFactory().getDefaultAddressSpace();
        FunctionManager fm = currentProgram.getFunctionManager();
        DecompInterface di = new DecompInterface();
        di.openProgram(currentProgram);
        String line;
        int ok = 0, miss = 0;
        while ((line = r.readLine()) != null) {
            line = line.trim();
            if (line.isEmpty()) continue;
            long a = Long.parseLong(line, 16);
            Function f = fm.getFunctionContaining(sp.getAddress(a));
            w.println("// ===== FUN_" + String.format("%08x", a) + " =====");
            if (f == null) { w.println("// (no function)\n"); miss++; continue; }
            DecompileResults res = di.decompileFunction(f, 45, monitor);
            if (res != null && res.decompileCompleted()) { w.println(res.getDecompiledFunction().getC()); ok++; }
            else { w.println("// decompile failed\n"); miss++; }
            w.println();
        }
        r.close();
        w.close();
        println("decompiled " + ok + " ok, " + miss + " missing -> " + args[1]);
    }
}
