import struct, subprocess, sys, os

def load_dol(path):
    with open(path, 'rb') as f:
        return f.read()

dol = load_dol('extracted/sys/main.dol')

funcs = [
    ('EndSaveGame', 0x80041B6C, 0x50),
    ('RetraceUpdate', 0x802E2D5C, 0x120),
    ('FrameComplete', 0x802E31FC, 0x60),
    ('GetMemoryUseSystemInfo', 0x802E3840, 0x50),
    ('GetMemoryUseGraphicsInfo?', 0x802E3868, 0x50),
]

objdump = 'F:/coding/Decompiles/Tools/devkitPro/devkitPPC/bin/powerpc-eabi-objdump'

for name, vaddr, size in funcs:
    for i in range(7):
        off = struct.unpack('>I', dol[i*4:i*4+4])[0]
        addr = struct.unpack('>I', dol[0x48+i*4:0x48+i*4+4])[0]
        sz = struct.unpack('>I', dol[0x90+i*4:0x90+i*4+4])[0]
        if addr <= vaddr < addr + sz:
            foff = off + (vaddr - addr)
            raw = dol[foff:foff+size]
            tmp = f'/tmp/dump_{name}_{vaddr:08x}.bin'
            os.makedirs('/tmp', exist_ok=True)
            with open(tmp, 'wb') as f:
                f.write(raw)
            print(f"\n=== {name} @ 0x{vaddr:08X} ({len(raw)} bytes) ===")
            subprocess.run([objdump, '-D', '-b', 'binary', '-m', 'powerpc:750', tmp])
            break
