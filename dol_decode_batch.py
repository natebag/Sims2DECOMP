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
    bd = (w & 0xfffc)
    if bd >= 0x8000: bd -= 0x10000
    aa = (w >> 1) & 1
    lk = w & 1
    bo = (w >> 21) & 0x1f
    bi = (w >> 16) & 0x1f
    
    # Common branches by hex prefix (more reliable)
    if (w & 0xFFFF0000) == 0x41820000:
        return f"beq {bd:+}"
    if (w & 0xFFFF0000) == 0x40820000:
        return f"bne {bd:+}"
    if (w & 0xFFFF0000) == 0x40810000:
        return f"ble {bd:+}"
    if (w & 0xFFFF0000) == 0x41810000:
        return f"bgt {bd:+}"
    if (w & 0xFFFF0000) == 0x409A0000:
        return f"bdnz {bd:+}"
    if w == 0x48000000:
        return "b"
    if (w & 0xFC000003) == 0x48000000:
        li = w & 3
        target = (w & 0x3FFFFFC)
        if target >= 0x2000000:
            target -= 0x4000000
        return f"b {target:+}"
    
    if w == 0x4e800020:
        return "blr"
    if w == 0x4c820020:
        return "beqlr"
    if w == 0x4d820020:
        return "bnelr"
    if w == 0x4c810020:
        return "bgelr"
    if w == 0x4c800020:
        return "bgtlr"  # or bclrl?
    
    if opc == 14:
        if ra == 0:
            return f"li r{rt}, {simm}"
        return f"addi r{rt}, r{ra}, {simm}"
    if opc == 15:
        return f"addis r{rt}, r{ra}, {simm}"
    if opc == 32:
        return f"lwz r{rt}, {simm}(r{ra})"
    if opc == 36:
        return f"stw r{rt}, {simm}(r{ra})"
    if opc == 40:
        return f"lhz r{rt}, {simm}(r{ra})"
    if opc == 44:
        return f"sth r{rt}, {simm}(r{ra})"
    if opc == 34:
        return f"lbz r{rt}, {simm}(r{ra})"
    if opc == 11:
        return f"cmpwi r0, r{ra}, {simm}"
    if opc == 10:
        return f"cmpli r0, r{ra}, {w & 0xffff}"
    if opc == 8:
        return f"subfic r{rt}, r{ra}, {simm}"
    if opc == 7:
        return f"mulli r{rt}, r{ra}, {simm}"
    
    if opc == 21:
        sh = rb
        mb = (w >> 6) & 0x1f
        me = (w >> 1) & 0x1f
        # Actually for rlwinm: mb=bits21-25, me=bits26-30
        mb = (w >> 6) & 0x1f  # wait, bits 21-25 from MSB = integer bits 6-10
        me = (w >> 1) & 0x1f  # bits 26-30 from MSB = integer bits 1-5
        return f"rlwinm r{ra}, r{rt}, {sh}, {mb}, {me}"
    
    if opc == 16:
        return f"bc bo={bo},bi={bi},{bd:+}"
    
    if opc == 31:
        if xo == 40:
            return f"subf r{rt}, r{ra}, r{rb}"
        if xo == 104:
            return f"neg r{rt}, r{ra}"
        if xo == 26:
            return f"cntlzw r{rt}, r{ra}"
        if xo == 28:
            return f"and r{rt}, r{ra}, r{rb}"
        if xo == 316:
            return f"xor r{rt}, r{ra}, r{rb}"
        if xo == 444:
            return f"or r{rt}, r{ra}, r{rb}"
        if xo == 412:
            return f"or r{rt}, r{ra}, r{rb}"
        if xo == 824:
            return f"srawi r{rt}, r{ra}, {rb}"
        if xo == 792:
            return f"sraw r{rt}, r{ra}, r{rb}"
        if xo == 23:
            return f"lwzx r{rt}, r{ra}, r{rb}"
        if xo == 151:
            return f"stwx r{rt}, r{ra}, r{rb}"
        if xo == 266:
            return f"add r{rt}, r{ra}, r{rb}"
        if xo == 0:
            return f"cmpw r0, r{ra}, r{rb}"
        if xo == 32:
            return f"cmplw r0, r{ra}, r{rb}"
        if xo == 138:
            return f"adde r{rt}, r{ra}, r{rb}"
        if xo == 339:
            return f"mflr r{rt}"
        if xo == 467:
            spr = ((w >> 16) & 0x3ff)
            if spr == 0x100:
                return f"mtlr r{ra}"
            if spr == 0x120:
                return f"mtctr r{ra}"
            return f"mtspr {spr}, r{ra}"
        return f"opc31 xo={xo} r{rt},r{ra},r{rb}"
    
    if opc == 37:
        return f"stwu r{rt}, {simm}(r{ra})"
    if opc == 19:
        if xo == 16:
            return f"bclr"
    
    return f"opc={opc} r{rt},r{ra},r{rb} simm={simm}"

targets = [
    (0x800AAA18, 40, "AmbientSoundPlayer::IsValid"),
    (0x800DCB50, 40, "cXObjectImpl::IsInWorld"),
    (0x8003E538, 40, "EGlobal::SetAuthorModeCheats"),
    (0x800F95B0, 40, "ObjectModuleImpl::GetSimFlag"),
    (0x800B0E44, 44, "cSoundModeManager::GetFrontEndMusicTrack"),
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
