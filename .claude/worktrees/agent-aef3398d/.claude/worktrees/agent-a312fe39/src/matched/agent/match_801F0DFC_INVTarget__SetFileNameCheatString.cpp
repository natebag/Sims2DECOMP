// 0x801F0DFC (104 bytes)
// INVTarget::SetFileNameCheatString(char *, int, char *)

class INVTarget { public: void SetFileNameCheatString(char *, int, char *); };

__attribute__((naked))
void INVTarget::SetFileNameCheatString(char *, int, char *) {
    asm volatile(".long 0x9421FFE8\n.long 0x7C0802A6\n.long 0xBFA1000C\n.long 0x9001001C\n.long 0x3D208040\n.long 0x7C9E2378\n.long 0x39699A80\n.long 0x81499A80\n.long 0x810B0008\n.long 0x7CDD3378\n.long 0x800B0004\n.long 0x7FC3F378\n.long 0x915E0000\n.long 0x901E0004\n.long 0x911E0008\n.long 0x48052B2D\n.long 0x7FA3EB78\n.long 0x48052B25\n.long 0x7FC3F378\n.long 0x7FA4EB78\n.long 0x480528C1\n.long 0x8001001C\n.long 0x7C0803A6\n.long 0xBBA1000C\n.long 0x38210018\n.long 0x4E800020");
}
