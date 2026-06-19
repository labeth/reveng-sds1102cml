import ghidra.app.script.GhidraScript;
import ghidra.program.model.address.Address;
import ghidra.program.model.symbol.*;
import ghidra.program.model.mem.*;
public class xr extends GhidraScript {
    @Override public void run() throws Exception {
        // PLANE-A 0x14=0x20200028, 0x15=0x2020002a. Find any pointer in memory equal to these (literal pool entries).
        long[] targets={0x20200028L,0x2020002aL};
        Memory mem=currentProgram.getMemory();
        for(long t:targets){
            int hits=0;
            for(MemoryBlock b: mem.getBlocks()){
                if(!b.isInitialized()) continue;
                Address s=b.getStart(), e=b.getEnd();
                for(Address ad=s; ad.compareTo(e)<0; ad=ad.add(4)){
                    try{ long v=getInt(ad)&0xffffffffL; if(v==t){ hits++; if(hits<=5) println(String.format("0x%x literal @%s",t,ad)); } }catch(Exception ex){break;}
                }
            }
            println(String.format("== 0x%x total literal-pool hits = %d ==",t,hits));
        }
    }
}
