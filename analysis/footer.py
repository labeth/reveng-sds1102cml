f="/mnt/c/Users/henri/Documents/ws/open-sds1102cml/tmp/SDS1000CML+_V6.01.01.25_EN/CML+_P25.ADS"
data=open(f,"rb").read()
N=len(data)
# Footer structured part begins ~0x650a8c. Parse the shifting 00..ff table
tail=data[0x650a90:]
print("tail from 0x650a90:",tail.hex())
# The "00..ff shifting" 
foot=data[0x650abc:]
print("\nshift table from 0x650abc:")
for i in range(0,len(foot),1):
    pass
# print as the pattern with offsets of ff
ffpos=[0x650abc+i for i,b in enumerate(foot) if b==0xff]
print("ff positions in shift region:",[hex(p) for p in ffpos])
print("gaps between ff:",[ffpos[i+1]-ffpos[i] for i in range(len(ffpos)-1)])

# Interpret last bytes
print("\nfinal 24 bytes:",data[-24:].hex())
import struct
# Check if footer encodes a length/count. N=6621932=0x650A6C
print("N=%d=0x%x"%(N,N))
# look at 0x650a8c region: '4c 4d 00 00 00 fc 00 01 37 c1 00 00 af 1a a5 88 3d 1f 54 d6 8f 3a 00 08 00 00 00 14 fb 03 4b 50'
hdr=data[0x650a8c:0x650abc]
print("pre-shift block 0x650a8c:",hdr.hex())
