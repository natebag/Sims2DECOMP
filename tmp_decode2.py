import struct

def sext(val, bits):
    if val & (1 << (bits - 1)):
        val -= 1 << bits
    return val

def decode(word, pc):
    opcode = (word >> 26) & 0x3f
    if opcode == 14:  # addi
        d = (word >> 21) & 0x1f
        a = (word >> 16) & 0x1f
        imm = sext(word & 0xffff, 16)
        if a == 0 and d != 0:
            return f"li      r{d}, {imm}"
        return f"addi    r{d}, r{a}, {imm}"
    elif opcode == 24:  # ori
        s = (word >> 21) & 0x1f
        a = (word >> 16) & 0x1f
        imm = word & 0xffff
        if s == 0 and a == 0 and imm == 0:
            return "nop"
        return f"ori     r{a}, r{s}, 0x{imm:04x}"
    elif opcode == 32:  # lwz
        d = (word >> 21) & 0x1f
        a = (word >> 16) & 0x1f
        imm = sext(word & 0xffff, 16)
        return f"lwz     r{d}, {imm}(r{a})"
    elif opcode == 33:  # lwzu
        d = (word >> 21) & 0x1f
        a = (word >> 16) & 0x1f
        imm = sext(word & 0xffff, 16)
        return f"lwzu    r{d}, {imm}(r{a})"
    elif opcode == 36:  # stw
        s = (word >> 21) & 0x1f
        a = (word >> 16) & 0x1f
        imm = sext(word & 0xffff, 16)
        return f"stw     r{s}, {imm}(r{a})"
    elif opcode == 37:  # stwu
        s = (word >> 21) & 0x1f
        a = (word >> 16) & 0x1f
        imm = sext(word & 0xffff, 16)
        return f"stwu    r{s}, {imm}(r{a})"
    elif opcode == 40:  # lhz
        d = (word >> 21) & 0x1f
        a = (word >> 16) & 0x1f
        imm = sext(word & 0xffff, 16)
        return f"lhz     r{d}, {imm}(r{a})"
    elif opcode == 42:  # lha
        d = (word >> 21) & 0x1f
        a = (word >> 16) & 0x1f
        imm = sext(word & 0xffff, 16)
        return f"lha     r{d}, {imm}(r{a})"
    elif opcode == 44:  # sth
        s = (word >> 21) & 0x1f
        a = (word >> 16) & 0x1f
        imm = sext(word & 0xffff, 16)
        return f"sth     r{s}, {imm}(r{a})"
    elif opcode == 11:  # cmpi
        d = (word >> 21) & 0x1f
        a = (word >> 16) & 0x1f
        imm = sext(word & 0xffff, 16)
        return f"cmpwi   cr{d}, r{a}, {imm}"
    elif opcode == 16:  # bc
        bo = (word >> 21) & 0x1f
        bi = (word >> 16) & 0x1f
        bd = sext((word & 0x3fff) << 2, 16)
        cond = ""
        if bo == 12 and bi == 2:
            cond = "beq"
        elif bo == 4 and bi == 2:
            cond = "bne"
        elif bo == 12:
            cond = f"bt {bi}"
        elif bo == 4:
            cond = f"bf {bi}"
        else:
            cond = f"bc {bo},{bi}"
        return f"{cond}     {pc+bd+4:08x}"
    elif opcode == 18:  # b/bl
        li = sext((word & 0x03fffffc), 26)
        lk = word & 1
        if lk:
            return f"bl      {pc+li+4:08x}"
        else:
            return f"b       {pc+li+4:08x}"
    elif opcode == 19:
        xo = (word >> 1) & 0x3ff
        if xo == 16:
            return "blr"
        elif xo == 444:
            s = (word >> 21) & 0x1f
            a = (word >> 16) & 0x1f
            b = (word >> 11) & 0x1f
            if s == b:
                return f"mr      r{a}, r{s}"
            return f"or      r{a}, r{s}, r{b}"
        elif xo == 24:
            s = (word >> 21) & 0x1f
            a = (word >> 16) & 0x1f
            return f"slw     r{a}, r{s}, r{a}"  # wait, slw is different
        elif xo == 412:
            s = (word >> 21) & 0x1f
            a = (word >> 16) & 0x1f
            sh = (word >> 11) & 0x1f
            mb = (word >> 6) & 0x1f
            return f"rlwimi  r{a}, r{s}, {sh}, {mb}, ???"
        elif xo == 0:
            d = (word >> 21) & 0x1f
            a = (word >> 16) & 0x1f
            b = (word >> 11) & 0x1f
            return f"cmpw    cr{d}, r{a}, r{b}"
        elif xo == 215:
            s = (word >> 21) & 0x1f
            a = (word >> 16) & 0x1f
            b = (word >> 11) & 0x1f
            return f"stbx    r{s}, r{a}, r{b}"
        elif xo == 341:
            return "mtcrf   ..."
        elif xo == 339:
            return "mfspr   ..."
        elif xo == 467:
            return "mtspr   ..."
        else:
            return f"xo={xo}"
    elif opcode == 31:
        xo = (word >> 1) & 0x3ff
        if xo == 0:
            d = (word >> 21) & 0x1f
            a = (word >> 16) & 0x1f
            b = (word >> 11) & 0x1f
            return f"cmpw    cr{d}, r{a}, r{b}"
        elif xo == 20:
            s = (word >> 21) & 0x1f
            a = (word >> 16) & 0x1f
            b = (word >> 11) & 0x1f
            return f"lwx     r{s}, r{a}, r{b}"
        elif xo == 23:
            s = (word >> 21) & 0x1f
            a = (word >> 16) & 0x1f
            b = (word >> 11) & 0x1f
            return f"lwzx    r{s}, r{a}, r{b}"
        elif xo == 40:
            d = (word >> 21) & 0x1f
            a = (word >> 16) & 0x1f
            b = (word >> 11) & 0x1f
            return f"subf    r{d}, r{b}, r{a}"
        elif xo == 144:
            d = (word >> 21) & 0x1f
            a = (word >> 16) & 0x1f
            return f"mtcrf   ..."
        elif xo == 339:
            d = (word >> 21) & 0x1f
            spr = (word >> 11) & 0x3ff
            if spr == 256:
                return f"mfspr   r{d}, lr"
            elif spr == 288:
                return f"mfspr   r{d}, ctr"
            return f"mfspr   r{d}, {spr}"
        elif xo == 467:
            s = (word >> 21) & 0x1f
            spr = (word >> 11) & 0x3ff
            if spr == 256:
                return f"mtspr   lr, r{s}"
            elif spr == 288:
                return f"mtspr   ctr, r{s}"
            return f"mtspr   {spr}, r{s}"
        elif xo == 28:
            s = (word >> 21) & 0x1f
            a = (word >> 16) & 0x1f
            b = (word >> 11) & 0x1f
            return f"and     r{a}, r{s}, r{b}"
        elif xo == 104:
            s = (word >> 21) & 0x1f
            a = (word >> 16) & 0x1f
            b = (word >> 11) & 0x1f
            return f"neg     r{a}, r{s}"
        elif xo == 136:
            s = (word >> 21) & 0x1f
            a = (word >> 16) & 0x1f
            b = (word >> 11) & 0x1f
            return f"subfe   r{a}, r{s}, r{b}"
        elif xo == 232:
            s = (word >> 21) & 0x1f
            a = (word >> 16) & 0x1f
            b = (word >> 11) & 0x1f
            return f"eqv     r{a}, r{s}, r{b}"
        elif xo == 316:
            s = (word >> 21) & 0x1f
            a = (word >> 16) & 0x1f
            return f"xor     r{a}, r{s}, ???"
        elif xo == 444:
            s = (word >> 21) & 0x1f
            a = (word >> 16) & 0x1f
            b = (word >> 11) & 0x1f
            if s == b:
                return f"mr      r{a}, r{s}"
            return f"or      r{a}, r{s}, r{b}"
        elif xo == 138:
            s = (word >> 21) & 0x1f
            a = (word >> 16) & 0x1f
            b = (word >> 11) & 0x1f
            return f"adde    r{a}, r{s}, r{b}"
        elif xo == 491:
            return f"lwsync"
        else:
            return f"xo31={xo}"
    elif opcode == 21:
        return f"rlwinm  ..."
    elif opcode == 59:
        return f"fd..."
    elif opcode == 63:
        return f"f..."
    elif opcode == 28:
        s = (word >> 21) & 0x1f
        a = (word >> 16) & 0x1f
        sh = (word >> 11) & 0x1f
        mb = (word >> 6) & 0x1f
        me = (word >> 1) & 0x1f
        if sh == 0 and mb == 0 and me == 31:
            return f"clrrwi  r{a}, r{s}, 0"
        return f"rlwinm  r{a}, r{s}, {sh}, {mb}, {me}"
    elif opcode == 20:
        s = (word >> 21) & 0x1f
        a = (word >> 16) & 0x1f
        sh = (word >> 11) & 0x1f
        mb = (word >> 6) & 0x1f
        me = (word >> 1) & 0x1f
        return f"rlwimi  r{a}, r{s}, {sh}, {mb}, {me}"
    elif opcode == 12:
        d = (word >> 21) & 0x1f
        a = (word >> 16) & 0x1f
        b = (word >> 11) & 0x1f
        o = (word >> 1) & 0x3ff
        return f"addic   r{d}, r{a}, {sext(word&0xffff,16)}"  # wrong, addic has imm
    elif opcode == 13:
        d = (word >> 21) & 0x1f
        a = (word >> 16) & 0x1f
        imm = sext(word & 0xffff, 16)
        return f"addic.  r{d}, r{a}, {imm}"
    elif opcode == 7:
        return f"mulli   ..."
    elif opcode == 8:
        d = (word >> 21) & 0x1f
        a = (word >> 16) & 0x1f
        imm = sext(word & 0xffff, 16)
        return f"subfic  r{d}, r{a}, {imm}"
    elif opcode == 34:
        d = (word >> 21) & 0x1f
        a = (word >> 16) & 0x1f
        imm = sext(word & 0xffff, 16)
        return f"lbz     r{d}, {imm}(r{a})"
    elif opcode == 38:
        s = (word >> 21) & 0x1f
        a = (word >> 16) & 0x1f
        imm = sext(word & 0xffff, 16)
        return f"stb     r{s}, {imm}(r{a})"
    else:
        return f"op={opcode}"

data = {
    0x800dd408: bytes.fromhex("9421ffe07c0802a6900100247c641b78386100084bfff9a180010014386000012c0000004082000838600000800100247c0803a6382100204e800020"),
    0x800dd49c: bytes.fromhex("9421ffe07c0802a6900100247c641b78386100084bfff90da861001a800100247c0803a6382100204e800020"),
    0x800eaa00: bytes.fromhex("9421fff87c0802a69001000c81630058a8830064812b0000a86900588009005c7c6b1a147c0803a64e8000218001000c7c0803a6382100084e800020"),
    0x800eaa80: bytes.fromhex("9421fff87c0802a69001000c8063000481230004a80902d8812902dc7c6302147d2803a64e800021686300018001000c7c0803a6382100084e800020"),
    0x800eaf44: bytes.fromhex("9421fff87c0802a69001000c386300283880003c4bff90e9a8030000386000012c00000040820008386000008001000c7c0803a6382100084e800020"),
    0x800eb004: bytes.fromhex("9421fff87c0802a69001000c81630058a8830064812b0000a86902388009023c7c6b1a147c0803a64e8000218001000c7c0803a6382100084e800020"),
    0x800eb080: bytes.fromhex("9421fff87c0802a69001000c81630058a8830064812b0000a8690230800902347c6b1a147c0803a64e8000218001000c7c0803a6382100084e800020"),
    0x800eb688: bytes.fromhex("9421fff87c0802a69001000c8063000481230004a80903988129039c7c6302147d2803a64e8000215463f7fe8001000c7c0803a6382100084e800020"),
    0x800eb89c: bytes.fromhex("7c691b78800900e82c0000004082000c386000004e8000203800000038600001900900e84e80002038000001900300e84e8000208123008c806900144e800020"),
}

for addr, raw in data.items():
    size = len(raw)
    # Trim to actual function size - look for blr and reasonable prologue/epilogue
    # For now just print all decoded
    print(f"\n=== 0x{addr:08x} ({size} bytes) ===")
    for i in range(0, size, 4):
        word = struct.unpack(">I", raw[i:i+4])[0]
        pc = addr + i
        print(f"  {pc:08x}: {word:08x}  {decode(word, pc)}")
