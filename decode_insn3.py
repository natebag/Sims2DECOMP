insn = 0x7c030378
b = format(insn, '032b')
print(f"Full: {b}")
print(f"opc:  {b[0:6]} = {int(b[0:6],2)}")
print(f"rt:   {b[6:11]} = {int(b[6:11],2)}")
print(f"ra:   {b[11:16]} = {int(b[11:16],2)}")
print(f"rb:   {b[16:21]} = {int(b[16:21],2)}")
print(f"xo:   {b[21:31]} = {int(b[21:31],2)}")
print(f"rc:   {b[31]} = {int(b[31])}")

# 2c000000
insn2 = 0x2c000000
b2 = format(insn2, '032b')
print(f"\n2c000000:")
print(f"opc:  {b2[0:6]} = {int(b2[0:6],2)}")
print(f"bf:   {b2[6:9]} = {int(b2[6:9],2)}")
print(f"l:    {b2[9:10]} = {int(b2[9:10])}")
print(f"ra:   {b2[10:15]} = {int(b2[10:15],2)}")
print(f"simm: {b2[16:32]} = {int(b2[16:32],2)}")
