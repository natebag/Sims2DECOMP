def decode(w):
    opc = (w >> 26) & 0x3f
    rt = (w >> 21) & 0x1f
    ra = (w >> 16) & 0x1f
    rb = (w >> 11) & 0x1f
    xo = (w >> 1) & 0x3ff  # bits 1-10 for some, but for opc=31 it's also bits 1-10
    # Actually for PPC X-form, the extended opcode is bits 21-30? No, for opcode 31 it's bits 1-10.
    # Wait, let me check: PPC instruction format: bits 0-5=opcode, bits 6-10=rt, 11-15=ra, 16-20=rb, 21-30=xo, 31=Rc
    # So xo should be bits 21-30.
    xo = (w >> 1) & 0x3ff  # This takes bits 1-10. That's wrong for X-form.
    # Correct: bits 21-30 = (w >> 1) & 0x3ff? Let's verify with bit positions:
    # bit 21 is the 11th bit from LSB (since bit 0 is MSB of 32-bit word in big-endian).
    # In the integer value, bit 31 is LSB, bit 0 is MSB.
    # So bit position from MSB: bit 21 corresponds to (w >> (31-21)) = (w >> 10).
    # Bits 21-30 are (w >> 1) & 0x3ff if we count from LSB as bit 0.
    # Wait, in PowerPC bit numbering, bit 0 is MSB. So bit 21 is the 22nd bit from the left.
    # In integer terms (LSB=bit 0), that's bit 32-1-21 = bit 10.
    # So bits 21-30 from MSB are bits 10-1 from LSB. That IS (w >> 1) & 0x3ff. So my function was correct!
    xo = (w >> 1) & 0x3ff
    simm = w & 0xffff
    if simm >= 0x8000:
        simm -= 0x10000
    return f"opc={opc} xo={xo} rt={rt} ra={ra} rb={rb} simm={simm}"

insns = [0x7c601850, 0x7c632e70, 0x3863ffff]
for insn in insns:
    print(f"{insn:08X}: {decode(insn)}")

# Map common xo values
xo_map = {
    40: "subf",
    26: "cntlzw",
    16: "blr",
    138: "adde",
    8: "subfic",
    554: "eieio",
    28: "and",
    60: "nor",
}
print("\nCommon xo mappings:")
for xo, name in xo_map.items():
    print(f"  {xo}: {name}")
