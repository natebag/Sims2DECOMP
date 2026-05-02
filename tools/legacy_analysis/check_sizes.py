import struct

with open('extracted/sys/main.dol','rb') as f:
    data = f.read()

def read_u32(off):
    return struct.unpack('>I', data[off:off+4])[0]

# Find which section contains each address
for name, addr in [
    ('EndSaveGame', 0x80041B6C),
    ('RetraceUpdate', 0x802E2D5C),
    ('FrameComplete', 0x802E31FC),
    ('GetMemoryUseSystemInfo', 0x802E3840),
]:
    for i in range(7):
        sec_addr = read_u32(0x48 + i*4)
        sec_off = read_u32(0x00 + i*4)
        sec_size = read_u32(0x90 + i*4)
        if sec_addr != 0 and sec_addr <= addr < sec_addr + sec_size:
            file_off = sec_off + (addr - sec_addr)
            raw = data[file_off:file_off+64]
            print(f"{name}: section {i} @ {addr:08X}, size field={sec_size}, file_off={file_off}")
            print(f"  bytes: {raw[:48].hex()}")
            break
    else:
        print(f"{name}: NOT FOUND")
