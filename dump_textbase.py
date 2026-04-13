import struct

with open('extracted/sys/main.dol', 'rb') as f:
    dol = f.read()
vaddr = 0x80084464
size = 84
for i in range(7):
    off = struct.unpack('>I', dol[i*4:i*4+4])[0]
    addr = struct.unpack('>I', dol[0x48+i*4:0x48+i*4+4])[0]
    sz = struct.unpack('>I', dol[0x90+i*4:0x90+i*4+4])[0]
    if addr <= vaddr < addr + sz:
        foff = off + (vaddr - addr)
        raw = dol[foff:foff+size]
        with open('build/textbase.bin', 'wb') as wf:
            wf.write(raw)
        print('Wrote %d bytes to build/textbase.bin' % len(raw))
        break
