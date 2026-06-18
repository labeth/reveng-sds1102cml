f="/mnt/c/Users/henri/Documents/ws/open-sds1102cml/tmp/SDS1000CML+_V6.01.01.25_EN/CML+_P25.ADS"
data=open(f,"rb").read()
N=len(data)
import collections
# count 8-byte block frequency (aligned)
c8=collections.Counter()
for i in range(0,N-8,8):
    c8[data[i:i+8]]+=1
print("=== Top aligned 8-byte blocks ===")
for blk,n in c8.most_common(15):
    print(n, blk.hex())
print("distinct 8-blocks:",len(c8),"of",(N//8))

# The repeating block a6a683100387 6e22 - find ALL its aligned offsets
target=bytes.fromhex("a6a6831003876e22")
offs=[i for i in range(0,N-8,8) if data[i:i+8]==target]
print("a6a6.. count(aligned):",len(offs),"first offsets:",[hex(o) for o in offs[:20]])
# spacing
if len(offs)>1:
    diffs=[offs[i+1]-offs[i] for i in range(len(offs)-1)]
    print("spacings:",diffs[:20])

# Also unaligned occurrences
import re
allo=[m.start() for m in re.finditer(re.escape(target),data)]
print("a6a6.. total(unaligned):",len(allo),"all aligned to 8?",all(o%8==0 for o in allo))
