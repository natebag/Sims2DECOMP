insns = [0x7c632278, 0x8865ffff, 0x7c030378, 0x7c691b78]

for insn in insns:
    opc = (insn >> 26) & 0x3f
    rt = (insn >> 21) & 0x1f
    ra = (insn >> 16) & 0x1f
    rb = (insn >> 11) & 0x1f
    xo = (insn >> 1) & 0x3ff
    rc = insn & 1
    
    name = "unknown"
    if opc == 31:
        names = {28:"and", 316:"xor", 444:"or", 467:"mtspr", 824:"srawi", 24:"slw", 536:"srw", 412:"or"}
        name = names.get(xo, f"xo={xo}")
    if opc == 34:
        name = "lbz"
    
    print(f"{insn:08X}: {name} r{rt}, r{ra}, r{rb} (rc={rc})")
