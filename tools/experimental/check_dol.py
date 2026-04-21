import struct
data = open("extracted/sys/main.dol","rb").read()
text_offset = struct.unpack(">I", data[0:4])[0]
text_addr = struct.unpack(">I", data[0x48:0x4c])[0]
file_off = lambda a: text_offset + (a - text_addr)
addr = 0x801dcdb4
print("48B:", data[file_off(addr):file_off(addr)+48].hex())
print("52B:", data[file_off(addr):file_off(addr)+52].hex())
print("Next 16B:", data[file_off(addr+48):file_off(addr+48)+16].hex())
