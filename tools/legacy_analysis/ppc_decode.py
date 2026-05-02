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
    aa = (w >> 1) & 1
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
    
    if opc == 14:
        return f"addi r{rt}, r{ra}, {simm}"
    if opc == 15:
        return f"addis r{rt}, r{ra}, {simm}"
    if opc == 24:
        return f"ori r{ra}, r{rs}, {uimm}"  # wait, rt/ra swapped in ori?
    if opc == 28:
        return f"andi. r{ra}, r{rt}, {uimm}"  # rt=rs, ra=ra in andi.
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
    
    if opc == 16:
        cond = ["","l","g","e","n"][bo] if bo < 5 else str(bo)
        return f"bc{cond} {bd:+}"
    
    if opc == 19:
        if xo == 16:
            return f"bclr"
        if xo == 528:
            return f"bcctr"
        if xo == 0:
            return f"mcrf"
        if xo == 150:
            return f"isync"
        if xo == 32:
            return f"crnor crb{rt}, crb{ra}, crb{rb}"
        if xo == 193:
            return f"crxor crb{rt}, crb{ra}, crb{rb}"
        if xo == 289:
            return f"creqv crb{rt}, crb{ra}, crb{rb}"
        if xo == 33:
            return f"crnor crb{rt}, crb{ra}, crb{rb}"
        if xo == 129:
            return f"crandc crb{rt}, crb{ra}, crb{rb}"
        if xo == 257:
            return f"crxor crb{rt}, crb{ra}, crb{rb}"
        if xo == 225:
            return f"crnand crb{rt}, crb{ra}, crb{rb}"
        if xo == 257:
            return f"crnor crb{rt}, crb{ra}, crb{rb}"
        if xo == 145:
            return f"crand crb{rt}, crb{ra}, crb{rb}"
        if xo == 33:
            return f"crnor crb{rt}, crb{ra}, crb{rb}"
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
            return f"orx r{rt}, r{ra}, r{rb}"  # or
        if xo == 412:
            return f"orx r{rt}, r{ra}, r{rb}"  # or with same regs = mr
        if xo == 215:
            return f"stbx r{rt}, r{ra}, r{rb}"
        if xo == 151:
            return f"stwx r{rt}, r{ra}, r{rb}"
        if xo == 23:
            return f"lwzx r{rt}, r{ra}, r{rb}"
        if xo == 824:
            # 824 = 0x338... what is this?
            # Actually let me check if it's srawi
            # srawi is opcode 31 with xo=824? Let me verify.
            # srawi encoding: opcode 31, xo=824 (0x338), yes! srawi rt, ra, sh
            sh = rb
            return f"srawi r{rt}, r{ra}, {sh}"
        if xo == 232:
            return f"subfme r{rt}, r{ra}"
        if xo == 234:
            return f"addme r{rt}, r{ra}"
        if xo == 138:
            return f"adde r{rt}, r{ra}, r{rb}"
        if xo == 491:
            return f"divwu r{rt}, r{ra}, r{rb}"
        if xo == 459:
            return f"divw r{rt}, r{ra}, r{rb}"
        if xo == 75:
            return f"mulhw r{rt}, r{ra}, r{rb}"
        if xo == 11:
            return f"mulhwu r{rt}, r{ra}, r{rb}"
        if xo == 235:
            return f"mullw r{rt}, r{ra}, r{rb}"
        if xo == 491:
            return f"divwu r{rt}, r{ra}, r{rb}"
        return f"opc31 xo={xo} rt={rt} ra={ra} rb={rb}"
    
    if opc == 59:
        return f"opc59"
    if opc == 63:
        return f"opc63"
    
    return f"opc={opc} rt={rt} ra={ra} rb={rb} simm={simm}"

# test
tests = [0x7c601850, 0x7c632e70, 0x3863ffff, 0x4e800020, 0x4c820020]
for t in tests:
    print(f"{t:08X}: {disasm(t)}")
