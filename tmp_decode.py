import struct

def decode_instr(word):
    opcode = (word >> 26) & 0x3f
    if opcode == 14:  # addi
        d = (word >> 21) & 0x1f
        a = (word >> 16) & 0x1f
        imm = word & 0xffff
        if imm & 0x8000:
            imm -= 65536
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
        imm = word & 0xffff
        if imm & 0x8000:
            imm -= 65536
        return f"lwz     r{d}, {imm}(r{a})"
    elif opcode == 36:  # stw
        s = (word >> 21) & 0x1f
        a = (word >> 16) & 0x1f
        imm = word & 0xffff
        if imm & 0x8000:
            imm -= 65536
        return f"stw     r{s}, {imm}(r{a})"
    elif opcode == 37:  # stwu
        s = (word >> 21) & 0x1f
        a = (word >> 16) & 0x1f
        imm = word & 0xffff
        if imm & 0x8000:
            imm -= 65536
        return f"stwu    r{s}, {imm}(r{a})"
    elif opcode == 16:  # bc/bne/etc
        bo = (word >> 21) & 0x1f
        bi = (word >> 16) & 0x1f
        bd = word & 0x3fff
        if bd & 0x2000:
            bd -= 0x4000
        bd *= 4
        return f"bc      ...  /* disp {bd:+d} */"
    elif opcode == 18:  # b/bl
        li = word & 0x03fffffc
        if li & 0x02000000:
            li -= 0x04000000
        aa = (word >> 1) & 1
        lk = word & 1
        if lk:
            return f"bl      ...  /* disp {li:+d} */"
        else:
            return f"b       ...  /* disp {li:+d} */"
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
        elif xo == 0:
            d = (word >> 21) & 0x1f
            a = (word >> 16) & 0x1f
            b = (word >> 11) & 0x1f
            return f"cmpw    cr{d}, r{a}, r{b}"
        else:
            return f"xo={xo}"
    else:
        return f"opcode={opcode}"

data = bytes.fromhex("9421fff07c0802a6bfc10008900100147c7e1b784bfd4f15907e003838000001901e000038600001800100147c0803a6bbc10008382100104e800020")
print("Start (0x800a88e0, 60 bytes):")
for i in range(0, 60, 4):
    word = struct.unpack(">I", data[i:i+4])[0]
    print(f"  {word:08x}  {decode_instr(word)}")

print("\nStop (0x800a891c):")
data2 = bytes.fromhex("9421fff87c0802a69001000c3800000090030000480006612c0300003860000041820008386000018001000c7c0803a6382100084e800020")
# Need to figure out exact size. Let's look at the next function.
for i in range(0, len(data2), 4):
    word = struct.unpack(">I", data2[i:i+4])[0]
    print(f"  {word:08x}  {decode_instr(word)}")
