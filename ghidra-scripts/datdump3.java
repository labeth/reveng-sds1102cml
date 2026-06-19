import ghidra.app.script.GhidraScript;
import ghidra.program.model.address.Address;
public class datdump3 extends GhidraScript {
    @Override public void run() throws Exception {
        long[] a = {
          0x1ae984L,0x1ae988L,   // FUN_001ae934 sel 0x07 ?
          0x1ae438L,0x1ae43cL,   // FUN_001ae3f0 primary 0x17/0x18
          0x1ae55cL,             // 0x44 enable strobe
          0x1ae590L,0x1ae5c4L,   // 0x35 writer/reader
          0x1ae88cL,             // 0x22 coupling
          0x1ae340L,0x1ae364L,   // 0x16 latch / unlatch
          0x1ae3e0L,0x1ae3e4L,0x1ae3e8L,0x1ae3ecL, // 0x27-0x2a cal32
          0x1b06c0L,0x1b06c4L,0x1b06c8L, // divisor 0x19/0x1a/0x1b
          0x1b0714L,             // 0x38 bit0 status
          0x1b0a88L,             // 0x38 bit5
          0x1b0bfcL,0x1b0c00L,   // 0x3b/0x3a position
          0x1aefb0L,0x1aefb4L,   // 0x41/0x59 roll
          0x1ae4d8L,0x1ae4dcL,0x1ae528L,0x1ae52cL // 0x3c/0x3d, 0x3e/0x58
        };
        String[] n = {
          "ae934.a","ae934.b","ae3f0.a(0x18?)","ae3f0.b(0x17?)","0x44","0x35w","0x35r","0x22",
          "0x16latch","0x16unlatch","0x27","0x28","0x29","0x2a","0x19","0x1a","0x1b","0x38b0","0x38b5",
          "0x3b","0x3a","0x41","0x59","ae490.a","ae490.b","ae4e0.a","ae4e0.b"};
        for (int i=0;i<a.length;i++){
            try { long v=getInt(toAddr(a[i]))&0xffffffffL;
              println(String.format("%-12s @%x = 0x%08x sel=0x%x",n[i],a[i],v,((v&0xffff)>>1)));
            } catch(Exception e){ println(n[i]+" err"); }
        }
    }
}
