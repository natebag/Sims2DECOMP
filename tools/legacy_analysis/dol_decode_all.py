import struct

def disasm(w, addr=0):
    opc = (w >> 26) & 0x3f
    rt = (w >> 21) & 0x1f
    ra = (w >> 16) & 0x1f
    rb = (w >> 11) & 0x1f
    xo = (w >> 1) & 0x3ff
    rc = w & 1
    simm = w & 0xffff
    if simm >= 0x8000:
        simm -= 0x10000
    uimm = w & 0xffff
    lk = w & 1
    bo = (w >> 21) & 0x1f
    bi = (w >> 16) & 0x1f
    bd = (w & 0xfffc)
    if bd >= 0x8000:
        bd -= 0x10000
    
    if w == 0x4e800020:
        return "blr"
    if w == 0x4c820020:
        return "beqlr"
    if w == 0x4d820020:
        return "bnelr"
    if w == 0x4c800420:
        return "bgelr"
    if w == 0x4c800020:
        return "bgelr"  # bo=4?
    
    if opc == 14:
        return f"addi r{rt}, r{ra}, {simm}"
    if opc == 15:
        return f"addis r{rt}, r{ra}, {simm}"
    if opc == 24:
        rs = rt
        return f"ori r{ra}, r{rs}, {uimm}"
    if opc == 26:
        rs = rt
        return f"xori r{ra}, r{rs}, {uimm}"
    if opc == 28:
        return f"andi. r{ra}, r{rt}, {uimm}"
    if opc == 32:
        return f"lwz r{rt}, {simm}(r{ra})"
    if opc == 36:
        return f"stw r{rt}, {simm}(r{ra})"
    if opc == 7:
        return f"mulli r{rt}, r{ra}, {simm}"
    if opc == 11:
        return f"cmpwi cr0, r{ra}, {simm}"
    if opc == 8:
        return f"subfic r{rt}, r{ra}, {simm}"
    if opc == 10:
        return f"cmpli cr0, r{ra}, {uimm}"
    if opc == 12:
        return f"addic r{rt}, r{ra}, {simm}"
    if opc == 13:
        return f"addic. r{rt}, r{ra}, {simm}"
    
    if opc == 16:
        conds = {0:"dnzf",1:"dne",2:"dnzt",3:"",4:"lt",5:"le",6:"eq",7:"ge",8:"gt",9:"ne",10:"dnz",12:"lt",13:"gt",14:"eq",15:"so"}
        c = conds.get(bo, str(bo))
        return f"b{c} {bd:+}"
    
    if opc == 18:
        li = w & 3
        aa = (w >> 1) & 1
        target = (w & 0x3fffffc)
        if target >= 0x2000000:
            target -= 0x4000000
        return f"b {target:+}"
    
    if opc == 19:
        if xo == 16:
            return f"bclr"
        return f"opc19 xo={xo}"
    
    if opc == 31:
        if xo == 40:
            return f"subf r{rt}, r{ra}, r{rb}"
        if xo == 104:
            return f"neg r{rt}, r{ra}"
        if xo == 26:
            return f"cntlzw r{rt}, r{ra}"
        if xo == 28:
            return f"and r{rt}, r{ra}, r{rb}"
        if xo == 60:
            return f"nor r{rt}, r{ra}, r{rb}"
        if xo == 444:
            return f"or r{rt}, r{ra}, r{rb}"
        if xo == 412:
            return f"or r{rt}, r{ra}, r{rb}"
        if xo == 215:
            return f"stbx r{rt}, r{ra}, r{rb}"
        if xo == 151:
            return f"stwx r{rt}, r{ra}, r{rb}"
        if xo == 23:
            return f"lwzx r{rt}, r{ra}, r{rb}"
        if xo == 824:
            sh = rb
            return f"srawi r{rt}, r{ra}, {sh}"
        if xo == 792:
            sh = rb
            return f"sraw r{rt}, r{ra}, r{sh}"
        if xo == 232:
            return f"subfme r{rt}, r{ra}"
        if xo == 234:
            return f"addme r{rt}, r{ra}"
        if xo == 138:
            return f"adde r{rt}, r{ra}, r{rb}"
        if xo == 75:
            return f"mulhw r{rt}, r{ra}, r{rb}"
        if xo == 11:
            return f"mulhwu r{rt}, r{ra}, r{rb}"
        if xo == 235:
            return f"mullw r{rt}, r{ra}, r{rb}"
        if xo == 491:
            return f"divwu r{rt}, r{ra}, r{rb}"
        if xo == 459:
            return f"divw r{rt}, r{ra}, r{rb}"
        if xo == 266:
            return f"add r{rt}, r{ra}, r{rb}"
        if xo == 40:
            return f"subf r{rt}, r{ra}, r{rb}"
        if xo == 0:
            return f"cmpw cr0, r{ra}, r{rb}"
        if xo == 32:
            return f"cmplw cr0, r{ra}, r{rb}"
        if xo == 478:
            return f"dcbst r{ra}, r{rb}"
        if xo == 150:
            return f"isync"
        if xo == 598:
            return f"sync"
        if xo == 310:
            return f"eciwx r{rt}, r{ra}, r{rb}"
        if xo == 438:
            return f"ecowx r{rt}, r{ra}, r{rb}"
        if xo == 136:
            return f"subfe r{rt}, r{ra}, r{rb}"
        if xo == 8:
            return f"subfc r{rt}, r{ra}, r{rb}"
        if xo == 10:
            return f"addc r{rt}, r{ra}, r{rb}"
        if xo == 200:
            return f"subfze r{rt}, r{ra}"
        if xo == 202:
            return f"addze r{rt}, r{ra}"
        return f"opc31 xo={xo} rt={rt} ra={ra} rb={rb}"
    
    if opc == 59:
        return f"opc59"
    if opc == 63:
        return f"opc63"
    
    return f"opc={opc} rt={rt} ra={ra} rb={rb} simm={simm}"

DOL = 'extracted/sys/main.dol'
with open(DOL, 'rb') as f:
    dol = f.read()

text_offsets = struct.unpack('>18I', dol[0x00:0x48])
text_addresses = struct.unpack('>18I', dol[0x48:0x90])

def get_dol_offset(vaddr):
    for i in range(7):
        sec_size = int.from_bytes(dol[0x90+i*4:0x94+i*4], 'big')
        if text_addresses[i] <= vaddr < text_addresses[i] + sec_size:
            return text_offsets[i] + (vaddr - text_addresses[i])
    return None

targets = [
    (0x8008FF18, 24, "LiveModeInitState::DatasetPendingAddRefAsync"),
    (0x8009018C, 24, "ChangeHouseLoadHouse::DatasetPendingAddRefAsync"),
    (0x80090BB8, 24, "LoadingScreenStateMachine::IsReadyToLoad"),
    (0x800922DC, 24, "MUStatesSaveNewGame::Reset"),
    (0x800EAA68, 24, "cXObjectImpl::GetMiscFlag"),
    (0x800EB218, 24, "cXObjectImpl::CountObjectSlots"),
    (0x80146998, 24, "TileWalls::HasWall"),
    (0x8017BF2C, 24, "UIHDTV::IsFoundNumberNegative"),
    (0x80183120, 24, "ActionMenu::MenuItem::GetNthItem"),
    (0x80190DF4, 24, "InteractionHelper::GetNext"),
    (0x801C1144, 24, "M2MTarget::GetMemCardPort"),
    (0x8021CEF0, 24, "FadeSquare::StopDraw"),
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
        print(f"  {addr+i:08X}: {w:08X}  {disasm(w)}")
    print()
