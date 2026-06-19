import ghidra.app.script.GhidraScript;
import ghidra.program.model.address.*;
import ghidra.program.model.symbol.*;
import ghidra.program.model.listing.*;
import java.io.*;
public class VP7 extends GhidraScript {
    void refs(PrintWriter w, AddressSpace sp, long a, String name) {
        Address ad = sp.getAddress(a);
        ReferenceManager rm = currentProgram.getReferenceManager();
        ReferenceIterator it = rm.getReferencesTo(ad);
        int n=0; StringBuilder s=new StringBuilder();
        while(it.hasNext()){ Reference r=it.next(); if(r.getReferenceType().isCall()||r.getReferenceType().isData()||r.getReferenceType().isFlow()){ s.append(r.getFromAddress()+"("+r.getReferenceType()+") "); n++; } }
        w.println("// "+name+" @0x"+Long.toHexString(a)+" : "+n+" refs : "+s);
    }
    @Override public void run() throws Exception {
        AddressSpace sp = currentProgram.getAddressFactory().getDefaultAddressSpace();
        String out = getScriptArgs().length>0?getScriptArgs()[0]:"/tmp/vp7.txt";
        PrintWriter w = new PrintWriter(new FileWriter(out));
        refs(w,sp,0x00029ed4L,"FUN_00029ed4 register");
        refs(w,sp,0x0002a028L,"FUN_0002a028 stop");
        refs(w,sp,0x00029f8cL,"FUN_00029f8c start");
        refs(w,sp,0x003f43d0L,"slot start");
        refs(w,sp,0x003f43d4L,"slot stop");
        w.close(); println("wrote "+out);
    }
}
