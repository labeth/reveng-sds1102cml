f="/mnt/c/Users/henri/Documents/ws/open-sds1102cml/tmp/SDS1000CML+_V6.01.01.25_EN/CML+_P25.ADS"
data=open(f,"rb").read()
N=len(data)
def hd(b,base=0):
    out=[]
    for i in range(0,len(b),16):
        chunk=b[i:i+16]
        hexs=' '.join('%02x'%x for x in chunk)
        asc=''.join(chr(x) if 32<=x<127 else '.' for x in chunk)
        out.append('%08x  %-47s  %s'%(base+i,hexs,asc))
    return '\n'.join(out)
print("=== FIRST 256 ===")
print(hd(data[:256],0))
print("=== LAST 512 ===")
print(hd(data[N-512:],N-512))
print("=== around 0x83000 (lowest entropy) ===")
print(hd(data[0x83000:0x83000+256],0x83000))
