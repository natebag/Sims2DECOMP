// 0x801E9138 (112 bytes)
// GetVar_GetCount::GetVar_GetCount(char *, int)

class GetVar_GetCount { public: void GetVar_GetCount(char *, int); };

__attribute__((naked))
void GetVar_GetCount::GetVar_GetCount(char *, int) {
    asm volatile(".long 0x9421FFE8\n.long 0x7C0802A6\n.long 0xBFA1000C\n.long 0x9001001C\n.long 0x3D208046\n.long 0x7C7E1B78\n.long 0x39297FD8\n.long 0x7CBD2B78\n.long 0x913E0008\n.long 0x7C832378\n.long 0x909E0000\n.long 0x4800066D\n.long 0x3D208046\n.long 0x907E0004\n.long 0x39297E78\n.long 0x3C808040\n.long 0x913E0008\n.long 0x3884878C\n.long 0x7FA5EB78\n.long 0x387E000C\n.long 0x4CC63182\n.long 0x480F56FD\n.long 0x7FC3F378\n.long 0x8001001C\n.long 0x7C0803A6\n.long 0xBBA1000C\n.long 0x38210018\n.long 0x4E800020");
}
