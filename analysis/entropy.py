import sys, math
f="/mnt/c/Users/henri/Documents/ws/open-sds1102cml/tmp/SDS1000CML+_V6.01.01.25_EN/CML+_P25.ADS"
data=open(f,"rb").read()
N=len(data)
print("len",N)
W=4096
def ent(b):
    if not b: return 0
    c=[0]*256
    for x in b: c[x]+=1
    e=0.0
    n=len(b)
    for v in c:
        if v:
            p=v/n
            e-=p*math.log2(p)
    return e
# print entropy per window, but compress runs
prev=None
start=0
rows=[]
for off in range(0,N,W):
    e=ent(data[off:off+W])
    rows.append((off,e))
# print summarized: group into bands
print("offset      entropy")
for i,(off,e) in enumerate(rows):
    # print every window but mark low
    pass
# Instead find low-entropy windows (<7.0)
low=[(off,e) for off,e in rows if e<7.5]
print("total windows",len(rows))
print("low-entropy(<7.5) windows:",len(low))
for off,e in low[:80]:
    print("LOW %#08x  %.3f"%(off,e))
# overall histogram of entropy
import collections
buckets=collections.Counter()
for off,e in rows:
    buckets[round(e,1)]+=1
print("entropy distribution (rounded .1):")
for k in sorted(buckets):
    print("  %.1f : %d"%(k,buckets[k]))
