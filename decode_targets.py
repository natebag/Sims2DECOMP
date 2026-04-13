import struct

def fmt_word(w):
    opc = (w >> 26) & 0x3F
    # lwz
    if opc == 32:
        rt = (w >> 21) & 0x1F
        ra = (w >> 16) & 0x1F
        d = w & 0xFFFF
        if d & 0x8000: d -= 0x10000
        return f"lwz r{rt}, {d}(r{ra})"
    # stw
    if opc == 36:
        rs = (w >> 21) & 0x1F
        ra = (w >> 16) & 0x1F
        d = w & 0xFFFF
        if d & 0x8000: d -= 0x10000
        return f"stw r{rs}, {d}(r{ra})"
    # addi / li
    if opc == 14:
        rt = (w >> 21) & 0x1F
        ra = (w >> 16) & 0x1F
        d = w & 0xFFFF
        if d & 0x8000: d -= 0x10000
        if ra == 0:
            return f"li r{rt}, {d}"
        return f"addi r{rt}, r{ra}, {d}"
    # cmpwi
    if opc == 11:
        bf = (w >> 23) & 0x7
        ra = (w >> 16) & 0x1F
        d = w & 0xFFFF
        if d & 0x8000: d -= 0x10000
        return f"cmpwi cr{bf}, r{ra}, {d}"
    # bc
    if opc == 16:
        bo = (w >> 21) & 0x1F
        bi = (w >> 16) & 0x1F
        bd = w & 0xFFFC
        if bd & 0x8000: bd -= 0x10000
        lk = w & 1
        return f"bc {bo},{bi},{bd:+d}" + (" (bl)" if lk else "")
    # b
    if opc == 18:
        li = w & 0x03FFFFFC
        if li & 0x02000000: li -= 0x04000000
        lk = w & 1
        return f"b {li:+d}" + (" (bl)" if lk else "")
    # add (opcode 31, xo 266)
    if opc == 31:
        xo = (w >> 1) & 0x3FF
        if xo == 266:
            rt = (w >> 21) & 0x1F
            ra = (w >> 16) & 0x1F
            rb = (w >> 11) & 0x1F
            return f"add r{rt}, r{ra}, r{rb}"
        if xo == 40:
            rt = (w >> 21) & 0x1F
            ra = (w >> 16) & 0x1F
            rb = (w >> 11) & 0x1F
            return f"subf r{rt}, r{ra}, r{rb}"
        if xo == 444:
            rt = (w >> 21) & 0x1F
            ra = (w >> 16) & 0x1F
            return f"or r{rt}, r{ra}, r{ra}"
        if xo == 460:
            rt = (w >> 21) & 0x1F
            ra = (w >> 16) & 0x1F
            return f"mr r{rt}, r{ra}"
    # mtlr
    if w == 0x7C0803A6:
        return "mtlr r0"
    # blr
    if w == 0x4E800020:
        return "blr"
    # mflr
    if w == 0x7C0802A6:
        return "mflr r0"
    # stwu
    if opc == 37:
        rs = (w >> 21) & 0x1F
        ra = (w >> 16) & 0x1F
        d = w & 0xFFFF
        if d & 0x8000: d -= 0x10000
        return f"stwu r{rs}, {d}(r{ra})"
    # lfs
    if opc == 48:
        rt = (w >> 21) & 0x1F
        ra = (w >> 16) & 0x1F
        d = w & 0xFFFF
        if d & 0x8000: d -= 0x10000
        return f"lfs f{rt}, {d}(r{ra})"
    return f"0x{w:08X}"

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
    for i in range(7):
        off = struct.unpack('>I', dol[i*4:i*4+4])[0]
        sec_addr = struct.unpack('>I', dol[0x48+i*4:0x48+i*4+4])[0]
        sz = struct.unpack('>I', dol[0x90+i*4:0x90+i*4+4])[0]
        if sec_addr <= addr < sec_addr + sz:
            foff = off + (addr - sec_addr)
            raw = dol[foff:foff+size]
            print(f"\n=== {name} @ 0x{addr:08X} ({len(raw)} bytes) ===")
            for j in range(0, len(raw), 4):
                w = struct.unpack('>I', raw[j:j+4])[0]
                print(f"  {j:02x}: {w:08X}  {fmt_word(w)}")
            break
