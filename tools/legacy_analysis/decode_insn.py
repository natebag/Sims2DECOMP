w = 0x4c820020
opc = (w >> 26) & 0x3f
xo = (w >> 1) & 0x3ff
bo = (w >> 21) & 0x1f
bi = (w >> 16) & 0x1f
lk = w & 1
print(f"opc={opc} xo={xo} bo={bo} bi={bi} lk={lk}")

# also decode 4d820020
w = 0x4d820020
opc = (w >> 26) & 0x3f
xo = (w >> 1) & 0x3ff
bo = (w >> 21) & 0x1f
bi = (w >> 16) & 0x1f
lk = w & 1
print(f"insn2: opc={opc} xo={xo} bo={bo} bi={bi} lk={lk}")
