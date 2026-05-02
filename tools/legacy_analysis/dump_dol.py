import sys

addr = 0x80211868
size = 88

with open('extracted/files/u2_ngc_release_dvd.elf', 'rb') as f:
    # Read ELF header
    f.seek(0x20)
    phoff = int.from_bytes(f.read(4), 'little')
    f.seek(0x2C)
    phentsize = int.from_bytes(f.read(2), 'little')
    phnum = int.from_bytes(f.read(2), 'little')
    
    for i in range(phnum):
        f.seek(phoff + i * phentsize)
        p_type = int.from_bytes(f.read(4), 'little')
        if p_type != 1:  # PT_LOAD
            continue
        p_offset = int.from_bytes(f.read(4), 'little')
        p_vaddr = int.from_bytes(f.read(4), 'little')
        p_paddr = int.from_bytes(f.read(4), 'little')
        p_filesz = int.from_bytes(f.read(4), 'little')
        
        if p_vaddr <= addr < p_vaddr + p_filesz:
            offset = p_offset + (addr - p_vaddr)
            f.seek(offset)
            data = f.read(size)
            for j in range(0, len(data), 4):
                print(data[j:j+4].hex())
            break
