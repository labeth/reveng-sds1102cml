f="/mnt/c/Users/henri/Documents/ws/open-sds1102cml/tmp/SDS1000CML+_V6.01.01.25_EN/CML+_P25.ADS"
data=open(f,"rb").read()
N=len(data)

# Region 0x54754: 6569de96 repeating period 4. Extract pure repeat region
seg=data[0x54758:0x547a8]
print("seg54 len",len(seg),"period check:")
for p in range(1,12):
    ok=all(seg[i]==seg[i%p] for i in range(len(seg)))
    if ok: print("  period",p,"=",seg[:p].hex())

# Region 0xaba87 c480f177 - extract
seg2=data[0xaba87:0xaba87+90]
print("\nseg_ab:",seg2[:40].hex())
for p in range(1,16):
    ok=all(seg2[i]==seg2[i%p] for i in range(len(seg2)))
    if ok: print("  period",p,"=",seg2[:p].hex())

# So if these are keystream over zero-plaintext, the global keystream is periodic.
# Test: is the WHOLE file XOR with a repeating key? Try Hamming-distance method for key length 1..64
def hamming(a,b):
    return sum(bin(x^y).count("1") for x,y in zip(a,b))
print("\n=== Kasiski/Hamming keylen search (whole file sample) ===")
sample=data[:262144]
results=[]
for kl in range(1,65):
    # average normalized hamming over several block pairs
    nb=len(sample)//kl
    if nb<4: continue
    tot=0;cnt=0
    for b in range(min(nb-1,200)):
        a=sample[b*kl:(b+1)*kl]
        c=sample[(b+1)*kl:(b+2)*kl]
        if len(a)==len(c)==kl:
            tot+=hamming(a,c)/kl; cnt+=1
    results.append((tot/cnt,kl))
results.sort()
print("lowest normalized hamming (best repeating-key candidates):")
for h,kl in results[:12]:
    print("  keylen %d : %.4f"%(kl,h))
