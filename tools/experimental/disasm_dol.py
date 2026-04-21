import struct
import subprocess
import sys
import tempfile
import os

data = open("extracted/sys/main.dol", "rb").read()
text_offset = struct.unpack(">I", data[0:4])[0]
text_addr = struct.unpack(">I", data[0x48:0x4c])[0]

addr = int(sys.argv[1], 16)
size = int(sys.argv[2])

file_off = text_offset + (addr - text_addr)
bytes_data = data[file_off:file_off+size]

with tempfile.NamedTemporaryFile(delete=False) as f:
    f.write(bytes_data)
    tmp = f.name

try:
    subprocess.run([
        r"F:\coding\Decompiles\Tools\devkitPro\devkitPPC\bin\powerpc-eabi-objdump.exe",
        "-b", "binary", "-m", "powerpc:750", "-EB", "-M", "gekko",
        "-D", "--adjust-vma", hex(addr), tmp
    ])
finally:
    os.unlink(tmp)
