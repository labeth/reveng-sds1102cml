f="/mnt/c/Users/henri/Documents/ws/open-sds1102cml/tmp/SDS1000CML+_V6.01.01.25_EN/CML+_P25.ADS"
data=open(f,"rb").read()
N=len(data)
import re,collections
# Locate the 6569de96 period-4 region
t=bytes.fromhex("6569de96")
offs=[m.start() for m in re.finditer(re.escape(t),data)]
print("6569de96 count:",len(offs))
print("offsets:",[hex(o) for o in offs])
if offs:
    lo=offs[0]-16; hi=offs[-1]+16
    seg=data[lo:hi]
    print("context %x..%x:"%(lo,hi), seg.hex())

# Locate c480f177 rotating family
t2=bytes.fromhex("480f177dc4")
o2=[m.start() for m in re.finditer(re.escape(bytes.fromhex("c480f177dc")),data)]
print("\nc480f177dc count:",len(o2),"offs:",[hex(o) for o in o2[:20]])
if o2:
    lo=o2[0]-8;hi=o2[-1]+24
    print("context:",data[lo:hi].hex())

# ffff regions - find largest run of 0xff
runs=[]
i=0
while i<N:
    if data[i]==0xff:
        j=i
        while j<N and data[j]==0xff: j+=1
        if j-i>=16: runs.append((i,j-i))
        i=j
    else: i+=1
runs.sort(key=lambda x:-x[1])
print("\nlongest 0xff runs:",[(hex(o),l) for o,l in runs[:10]])
print("num ff-runs>=16:",len(runs),"total ff bytes in runs:",sum(l for _,l in runs))
