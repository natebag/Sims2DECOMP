import struct, subprocess

objdump = '/f/coding/Decompiles/Tools/devkitPro/devkitPPC/bin/powerpc-eabi-objdump'

targets = [
    (0x800B0EF0, 0x18, "GetDemoMusicTrack"),
    (0x800B7898, 0x18, "GetGameMode"),
    (0x80328374, 0x20, "GetHeap"),
    (0x803570D4, 0x18, "IsEffectRunning"),
    (0x803570B4, 0x20, "IsEffectRamping"),
    (0x8036C33C, 0x20, "GetHeap2"),
]

with open('extracted/sys/main.dol', 'rb') as f:
    dol = f.read()

for addr, size, name in targets:
    found = False
    for i in range(7):
        off = struct.unpack('>I', dol[i*4:i*4+4])[0]
        sec_addr = struct.unpack('>I', dol[0x48+i*4:0x48+i*4+4])[0]
        sz = struct.unpack('>I', dol[0x90+i*4:0x90+i*4+4])[0]
        if sec_addr <= addr < sec_addr + sz:
            foff = off + (addr - sec_addr)
            raw = dol[foff:foff+size]
            tmp = f'build/verify/{name}_{addr:08x}.bin'
            with open(tmp, 'wb') as f2:
                f2.write(raw)
            result = subprocess.run(['bash', '-c', f'{objdump} -D -b binary -m powerpc:750 {tmp}'],
                                   capture_output=True, text=True)
            print(f"\n=== {name} @ 0x{addr:08X} ({len(raw)} bytes) ===")
            print(result.stdout)
            found = True
            break
    if not found:
        print(f"\n=== {name} @ 0x{addr:08X} NOT FOUND in any DOL section ===")
