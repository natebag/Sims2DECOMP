import struct, subprocess, tempfile, os

with open("extracted/sys/main.dol", "rb") as f:
    dol = f.read()

vaddr = 0x8007E6D8
foff = None
for i in range(7):
    off = struct.unpack(">I", dol[i*4:i*4+4])[0]
    addr = struct.unpack(">I", dol[0x48+i*4:0x48+i*4+4])[0]
    sz = struct.unpack(">I", dol[0x90+i*4:0x90+i*4+4])[0]
    if addr <= vaddr < addr + sz:
        foff = off + (vaddr - addr)
        break

if foff is None:
    for i in range(11):
        off = struct.unpack(">I", dol[0x1C+i*4:0x1C+i*4+4])[0]
        addr = struct.unpack(">I", dol[0x64+i*4:0x64+i*4+4])[0]
        sz = struct.unpack(">I", dol[0xAC+i*4:0xAC+i*4+4])[0]
        if addr <= vaddr < addr + sz:
            foff = off + (vaddr - addr)
            break

raw = dol[foff:foff+80]
with tempfile.NamedTemporaryFile(suffix=".bin", delete=False) as tmp:
    tmp.write(raw)
    tmp_path = tmp.name

objdump = "F:/coding/Decompiles/Tools/devkitPro/devkitPPC/bin/powerpc-eabi-objdump.exe"
result = subprocess.run(
    [objdump, "-D", "-m", "powerpc", "-EB", "-b", "binary",
     f"--adjust-vma=0x{vaddr:08X}", tmp_path],
    capture_output=True, text=True
)
print(result.stdout)
os.unlink(tmp_path)
