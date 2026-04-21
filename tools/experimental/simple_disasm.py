import sys

def sext(val, bits):
    if val & (1 << (bits - 1)):
        val -= 1 << bits
    return val

def disasm_one(data, addr):
    inst = int.from_bytes(data, 'big')
    op = (inst >> 26) & 0x3f
    
    def rD(): return (inst >> 21) & 0x1f
    def rA(): return (inst >> 16) & 0x1f
    def rB(): return (inst >> 11) & 0x1f
    def imm16(): return sext(inst & 0xffff, 16)
    def uimm16(): return inst & 0xffff
    
    # branches
    if op == 18:
        aa = (inst >> 1) & 1
        lk = inst & 1
        li = sext(inst & 0x03fffffc, 26)
        if aa:
            target = li
        else:
            target = addr + li
        name = 'bla' if (aa and lk) else 'ba' if aa else 'bl' if lk else 'b'
        return f"{name} 0x{target:08x}"
    if op == 16:
        bo = (inst >> 21) & 0x1f
        bi = (inst >> 16) & 0x1f
        bd = sext((inst & 0xfffc), 16)
        aa = (inst >> 1) & 1
        lk = inst & 1
        target = bd if aa else addr + bd
        conds = {0:'dnz', 2:'dz'}
        signs = {0:'f', 1:'t', 2:'f', 3:'t'}
        name = 'b' + ("l" if lk else "")
        if bo & 4:
            if bo & 2:
                name += 'dnzf' if (bo & 1) == 0 else 'dnzt'
            else:
                name += 'f' if (bo & 1) == 0 else 't'
        else:
            name += 'dnz' if (bo & 2) else 'dz' if (bo & 14) == 8 else '??'
        if bi == 28:
            name = name.replace('dnz', '').replace('dz', '')
            name = 'blt' if name.startswith('b') else name
            name = name.replace('??', '')
        elif bi == 29:
            name = name.replace('dnz', '').replace('dz', '')
            name = 'bgt' if name.startswith('b') else name
            name = name.replace('??', '')
        elif bi == 30:
            name = name.replace('dnz', '').replace('dz', '')
            name = 'beq' if name.startswith('b') else name
            name = name.replace('??', '')
        elif bi == 31:
            name = name.replace('dnz', '').replace('dz', '')
            name = 'bso' if name.startswith('b') else name
            name = name.replace('??', '')
        if aa: name += 'a'
        return f"{name} 0x{target:08x}"
    
    # common ops
    if op == 14: return f"addi r{rD()}, r{rA()}, {imm16()}"
    if op == 15: return f"addis r{rD()}, r{rA()}, {imm16()}"
    if op == 24: return f"ori r{rD()}, r{rA()}, {uimm16()}"
    if op == 25: return f"oris r{rD()}, r{rA()}, {uimm16()}"
    if op == 28: return f"andi. r{rD()}, r{rA()}, {uimm16()}"
    if op == 32: return f"lwz r{rD()}, {imm16()}(r{rA()})"
    if op == 33: return f"lwzu r{rD()}, {imm16()}(r{rA()})"
    if op == 34: return f"lbz r{rD()}, {imm16()}(r{rA()})"
    if op == 35: return f"lbzu r{rD()}, {imm16()}(r{rA()})"
    if op == 36: return f"stw r{rD()}, {imm16()}(r{rA()})"
    if op == 37: return f"stwu r{rD()}, {imm16()}(r{rA()})"
    if op == 38: return f"stb r{rD()}, {imm16()}(r{rA()})"
    if op == 40: return f"lhz r{rD()}, {imm16()}(r{rA()})"
    if op == 41: return f"lhzu r{rD()}, {imm16()}(r{rA()})"
    if op == 42: return f"lha r{rD()}, {imm16()}(r{rA()})"
    if op == 43: return f"lhau r{rD()}, {imm16()}(r{rA()})"
    if op == 44: return f"sth r{rD()}, {imm16()}(r{rA()})"
    if op == 11: return f"cmpi cr{rD()//4}, {rD()&1}, r{rA()}, {imm16()}"
    if op == 10: return f"cmpli cr{rD()//4}, {rD()&1}, r{rA()}, {uimm16()}"
    
    if op == 31:
        xo = (inst >> 1) & 0x3ff
        if xo == 0: return f"cmp cr{rD()//4}, {rD()&1}, r{rA()}, r{rB()}"
        if xo == 32: return f"cmpl cr{rD()//4}, {rD()&1}, r{rA()}, r{rB()}"
        if xo == 26: return f"mfcr r{rD()}"
        if xo == 19: return f"mfctr r{rD()}"
        if xo == 339: return f"mfspr r{rD()}, {((rA()&0x1f)<<5)|(rB()&0x1f)}"
        if xo == 467: return f"mtspr {((rA()&0x1f)<<5)|(rB()&0x1f)}, r{rD()}"
        if xo == 144: return f"mtcrf {((rD()>>1)&0x7f)}, r{rD()}"
        if xo == 444: return f"orx r{rA()}, r{rD()}, r{rB()}"  # approximate
        if xo == 476: return f"nand r{rA()}, r{rD()}, r{rB()}"
        if xo == 412: return f"or r{rA()}, r{rD()}, r{rB()}"
        if xo == 124: return f"nor r{rA()}, r{rD()}, r{rB()}"
        if xo == 284: return f"eqv r{rA()}, r{rD()}, r{rB()}"
        if xo == 316: return f"xor r{rA()}, r{rD()}, r{rB()}"
        if xo == 444: return f"or r{rA()}, r{rD()}, r{rB()}"
        if xo == 24: return f"slw r{rA()}, r{rD()}, r{rB()}"
        if xo == 536: return f"srw r{rA()}, r{rD()}, r{rB()}"
        if xo == 792: return f"sraw r{rA()}, r{rD()}, r{rB()}"
        if xo == 824: return f"srawi r{rA()}, r{rD()}, {rB()}"
        if xo == 28: return f"and r{rA()}, r{rD()}, r{rB()}"
        if xo == 60: return f"andc r{rA()}, r{rD()}, r{rB()}"
        if xo == 40: return f"subf r{rA()}, r{rB()}, r{rD()}"
        if xo == 266: return f"add r{rA()}, r{rD()}, r{rB()}"
        if xo == 491: return f"mtlr r{rD()}"
        if xo == 339: return f"mfspr r{rD()}, ???"
        if xo == 19: return f"mfctr r{rD()}"
        if xo == 467: return f"mtspr ???, r{rD()}"
        rc = inst & 1
        return f"xo_{xo} r{rD()}, r{rA()}, r{rB()}" + ("." if rc else "")
    
    # rlwinm etc
    if op == 21:
        sh = (inst >> 11) & 0x1f
        mb = (inst >> 6) & 0x1f
        me = (inst >> 1) & 0x1f
        rc = inst & 1
        return f"rlwinm{r('.' if rc else '')} r{rA()}, r{rD()}, {sh}, {mb}, {me}"
    if op == 20:
        sh = (inst >> 11) & 0x1f
        rc = inst & 1
        return f"rlwimi{r('.' if rc else '')} r{rA()}, r{rD()}, {sh}, {(inst>>6)&0x1f}, {(inst>>1)&0x1f}"
    
    if op == 19:
        xo = (inst >> 1) & 0x3ff
        if xo == 528: return f"bcctr{b'l' if inst&1 else ''}"
        if xo == 16: return f"bclr{b'l' if inst&1 else ''}"
        return f"op19_xo{xo}"
    
    return f".long 0x{inst:08x}"

def r(s): return s

def disasm(data, base_addr=0):
    for i in range(0, len(data), 4):
        inst = data[i:i+4]
        if len(inst) < 4: break
        addr = base_addr + i
        print(f"{addr:08x}: {inst.hex()}  {disasm_one(inst, addr)}")

if __name__ == '__main__':
    addr = int(sys.argv[1], 0) if len(sys.argv) > 1 else 0
    size = int(sys.argv[2]) if len(sys.argv) > 2 else 0
    import struct
    with open("extracted/sys/main.dol", "rb") as f:
        dol = f.read()
    for i in range(7):
        off = struct.unpack(">I", dol[i*4:i*4+4])[0]
        base = struct.unpack(">I", dol[0x48+i*4:0x48+i*4+4])[0]
        sz = struct.unpack(">I", dol[0x90+i*4:0x90+i*4+4])[0]
        if base <= addr < base + sz:
            foff = off + (addr - base)
            raw = dol[foff:foff+size]
            disasm(raw, addr)
            break
