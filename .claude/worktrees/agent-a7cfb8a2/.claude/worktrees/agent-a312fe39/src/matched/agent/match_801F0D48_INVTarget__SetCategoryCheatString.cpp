// 0x801F0D48 (112 bytes)
// INVTarget::SetCategoryCheatString(char *, int, char *)

class INVTarget { public: void SetCategoryCheatString(char *, int, char *); };

__attribute__((naked))
void INVTarget::SetCategoryCheatString(char *, int, char *) {
    asm volatile(".long 0x9421FFE8\n.long 0x7C0802A6\n.long 0xBFA1000C\n.long 0x9001001C\n.long 0x3D608040\n.long 0x7C9E2378\n.long 0x814B9A64\n.long 0x392B9A64\n.long 0x8909000A\n.long 0x7CDD3378\n.long 0x81690004\n.long 0x7FC3F378\n.long 0xA0090008\n.long 0x915E0000\n.long 0x917E0004\n.long 0xB01E0008\n.long 0x991E000A\n.long 0x48052BD9\n.long 0x7FA3EB78\n.long 0x48052BD1\n.long 0x7FC3F378\n.long 0x7FA4EB78\n.long 0x4805296D\n.long 0x8001001C\n.long 0x7C0803A6\n.long 0xBBA1000C\n.long 0x38210018\n.long 0x4E800020");
}
