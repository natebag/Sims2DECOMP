// 0x80161998 (104 bytes)
// CasGenetics::Grandparent::~Grandparent(void)

class CasGenetics { public: void Grandparent::~Grandparent(void); };

__attribute__((naked))
void CasGenetics::Grandparent::~Grandparent(void) {
    asm volatile(".long 0x9421FFE8\n.long 0x7C0802A6\n.long 0xBFA1000C\n.long 0x9001001C\n.long 0x7C7F1B78\n.long 0x7C9D2378\n.long 0x807F0000\n.long 0x2C030000\n.long 0x41820008\n.long 0x4816F865\n.long 0x3BC00000\n.long 0x93DF0000\n.long 0x807F0004\n.long 0x2C030000\n.long 0x4182000C\n.long 0x481B059D\n.long 0x93DF0004\n.long 0x73A00001\n.long 0x4182000C\n.long 0x7FE3FB78\n.long 0x4816F839\n.long 0x8001001C\n.long 0x7C0803A6\n.long 0xBBA1000C\n.long 0x38210018\n.long 0x4E800020");
}
