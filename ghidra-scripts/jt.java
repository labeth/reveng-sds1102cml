import ghidra.app.script.GhidraScript;
public class jt extends GhidraScript {
    @Override public void run() throws Exception {
        // jump table region @0x1b1140 - dump as shorts
        long base=0x1b1140L;
        for (int i=0;i<20;i++){
            long off=base+i*2;
            try{ int v=getShort(toAddr(off))&0xffff;
              println(String.format("idx? @%x short=0x%04x",off,v));
            }catch(Exception e){println("err "+off);}
        }
    }
}
