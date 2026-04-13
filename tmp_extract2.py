import struct

with open("extracted/sys/main.dol", "rb") as f:
    dol = f.read()

for addr in [0x800dd408, 0x800dd49c, 0x800eaa00, 0x800eaa80, 0x800eaf44, 0x800eb004, 0x800eb080, 0x800eb688, 0x800eb89c]:
    for i in range(7):
        off = struct.unpack(">I", dol[i*4:i*4+4])[0]
        vaddr = struct.unpack(">I", dol[0x48+i*4:0x48+i*4+4])[0]
        sz = struct.unpack(">I", dol[0x90+i*4:0x90+i*4+4])[0]
        if vaddr <= addr < vaddr + sz:
            foff = off + (addr - vaddr)
            # Read enough to determine size - use next address or 64 bytes
            raw = dol[foff:foff+64]
            print(f"{addr:08x}: {raw.hex()}")
            break
