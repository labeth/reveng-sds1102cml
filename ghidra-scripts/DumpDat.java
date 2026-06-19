import ghidra.app.script.GhidraScript;
import ghidra.program.model.address.Address;
import ghidra.program.model.mem.MemoryAccessException;

public class DumpDat extends GhidraScript {
    @Override
    public void run() throws Exception {
        long[] a = {0x1add58L,0x1add5cL,0x1add60L,0x1add64L,0x1add68L,0x1add6cL,
                    0x1add70L,0x1add74L,0x1add78L,0x1add7cL,
                    0x1ade84L,0x1ade88L,0x1ade8cL,0x1ade90L,0x1ade7cL,0x1ade80L,
                    0x765dcL,0x765e0L};
        String[] n = {"DAT_001add58","DAT_001add5c","DAT_001add60","DAT_001add64","DAT_001add68(c8.c)","DAT_001add6c(c2.10)",
                    "DAT_001add70(c8.c)","DAT_001add74(c8.10)","DAT_001add78(c3.c)","DAT_001add7c(c3.10)",
                    "DAT_001ade84","DAT_001ade88","DAT_001ade8c","DAT_001ade90","DAT_001ade7c","DAT_001ade80",
                    "DAT_000765dc","DAT_000765e0"};
        for (int i=0;i<a.length;i++){
            Address ad = toAddr(a[i]);
            try { long v = getInt(ad) & 0xffffffffL;
                println(String.format("%s @%x = 0x%08x  (sel=(v&ffff)>>1=0x%x)", n[i], a[i], v, ((v&0xffff)>>1)));
            } catch(Exception e){ println(n[i]+" err "+e); }
        }
    }
}
