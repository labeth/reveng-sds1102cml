import ghidra.app.script.GhidraScript;
import ghidra.program.model.address.Address;
import ghidra.program.model.listing.Function;
public class datdump2 extends GhidraScript {
    @Override public void run() throws Exception {
        long[] a = {0x1b0814L, 0x1b0860L, 0x1b083cL};
        for (long x : a) {
            Address ad = toAddr(x);
            Function f = getFunctionAt(ad);
            try { long v = getInt(ad) & 0xffffffffL;
              println(String.format("@%x int=0x%08x  func=%s", x, v, (f==null?"NONE":f.getName())));
            } catch(Exception e){ println(String.format("@%x readErr func=%s", x, (f==null?"NONE":f.getName()))); }
        }
        // find any instruction writing 0xca near 0x21 region: scan references to 0x20200042 selector dat
    }
}
