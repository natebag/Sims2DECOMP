import struct

DOL = 'extracted/sys/main.dol'

def get_dol_offset(vaddr):
    with open(DOL, 'rb') as f:
        dol = f.read()
    text_offsets = struct.unpack('>7I', dol[0x00:0x1C])
    data_offsets = struct.unpack('>11I', dol[0x1C:0x48])
    text_addresses = struct.unpack('>7I', dol[0x48:0x64])
    data_addresses = struct.unpack('>11I', dol[0x64:0x90])
    text_sizes = struct.unpack('>7I', dol[0x90:0xAC])
    data_sizes = struct.unpack('>11I', dol[0xAC:0xD8])
    
    all_offsets = list(text_offsets) + list(data_offsets)
    all_addresses = list(text_addresses) + list(data_addresses)
    all_sizes = list(text_sizes) + list(data_sizes)
    
    for i in range(18):
        if all_addresses[i] <= vaddr < all_addresses[i] + all_sizes[i]:
            return all_offsets[i] + (vaddr - all_addresses[i])
    return None

def decode_insn(w):
    opc = (w >> 26) & 0x3f
    rt = (w >> 21) & 0x1f
    ra = (w >> 16) & 0x1f
    rb = (w >> 11) & 0x1f
    xo = (w >> 1) & 0x3ff
    rc = w & 1
    simm = w & 0xffff
    if simm >= 0x8000: simm -= 0x10000
    
    if w == 0x4e800020: return "blr"
    if w == 0x4c820020: return "beqlr"
    if w == 0x4d820020: return "bnelr"
    if w == 0x4c810020: return "bgelr"
    
    if (w & 0xFFFF0000) == 0x41820000: return f"beq {(w & 0xfffc) - 0x10000 if (w & 0xfffc) >= 0x8000 else (w & 0xfffc):+}"
    if (w & 0xFFFF0000) == 0x40820000: return f"bne {(w & 0xfffc) - 0x10000 if (w & 0xfffc) >= 0x8000 else (w & 0xfffc):+}"
    if (w & 0xFFFF0000) == 0x40810000: return f"ble {(w & 0xfffc) - 0x10000 if (w & 0xfffc) >= 0x8000 else (w & 0xfffc):+}"
    if (w & 0xFFFF0000) == 0x41810000: return f"bgt {(w & 0xfffc) - 0x10000 if (w & 0xfffc) >= 0x8000 else (w & 0xfffc):+}"
    if (w & 0xFC000003) == 0x48000000:
        target = (w & 0x3FFFFFC)
        if target >= 0x2000000: target -= 0x4000000
        return f"b {target:+}"
    
    if opc == 14:
        if ra == 0: return f"li r{rt}, {simm}"
        return f"addi r{rt}, r{ra}, {simm}"
    if opc == 32:
        return f"lwz r{rt}, {simm}(r{ra})"
    if opc == 36:
        return f"stw r{rt}, {simm}(r{ra})"
    if opc == 11:
        return f"cmpwi r0, r{ra}, {simm}"
    if opc == 8:
        return f"subfic r{rt}, r{ra}, {simm}"
    if opc == 7:
        return f"mulli r{rt}, r{ra}, {simm}"
    
    if opc == 21:
        sh = rb
        mb = (w >> 6) & 0x1f
        me = (w >> 1) & 0x1f
        return f"rlwinm r{ra}, r{rt}, {sh}, {mb}, {me}"
    
    if opc == 31:
        if xo == 40: return f"subf r{rt}, r{ra}, r{rb}"
        if xo == 28: return f"and r{rt}, r{ra}, r{rb}"
        if xo == 316: return f"xor r{rt}, r{ra}, r{rb}"
        if xo == 444: return f"or r{rt}, r{ra}, r{rb}"
        if xo == 412: return f"or r{rt}, r{ra}, r{rb}"
        if xo == 824: return f"srawi r{ra}, r{rt}, {rb}"
        if xo == 23: return f"lwzx r{rt}, r{ra}, r{rb}"
        if xo == 151: return f"stwx r{rt}, r{ra}, r{rb}"
        if xo == 266: return f"add r{rt}, r{ra}, r{rb}"
        if xo == 138: return f"adde r{rt}, r{ra}, r{rb}"
        return f"opc31 xo={xo}"
    
    if opc == 37:
        return f"stwu r{rt}, {simm}(r{ra})"
    
    return f"opc={opc}"

targets = [
    (0x8009B8FC, 40, "BitArray64::operator|="),
    (0x800391B4, 40, "EyeToyClient::IsSlotOpenForCASImage"),
    (0x800911B8, 52, "LoadingScreenFadeInState::IsLoadComplete"),
    (0x801534CC, 52, "XRoute::ResetGoals"),
]

for addr, size, name in targets:
    offset = get_dol_offset(addr)
    if offset is None:
        print(f"Could not find {name}")
        continue
    with open(DOL, 'rb') as f:
        f.seek(offset)
        data = f.read(size)
    
    print(f"=== {name} @ 0x{addr:08X} ({size}B) ===")
    for i in range(0, len(data), 4):
        w = struct.unpack('>I', data[i:i+4])[0]
        print(f"  {addr+i:08X}: {w:08X}  {decode_insn(w)}")
    print()
