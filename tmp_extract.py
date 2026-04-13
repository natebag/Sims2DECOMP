import struct

with open("extracted/sys/main.dol", "rb") as f:
    dol = f.read()

for addr, size in [(0x800a88e0, 64), (0x800a891c, 64)]:
    for i in range(7):
        off = struct.unpack(">I", dol[i*4:i*4+4])[0]
        vaddr = struct.unpack(">I", dol[0x48+i*4:0x48+i*4+4])[0]
        sz = struct.unpack(">I", dol[0x90+i*4:0x90+i*4+4])[0]
        if vaddr <= addr < vaddr + sz:
            foff = off + (addr - vaddr)
            raw = dol[foff:foff+size]
            print(f"{addr:08x}: {raw.hex()}")
            break
