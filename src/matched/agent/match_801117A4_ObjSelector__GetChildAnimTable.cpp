// 0x801117A4 (96 bytes)
// ObjSelector::GetChildAnimTable(void)

class ObjSelector { public: void GetChildAnimTable(void); };

__attribute__((naked))
void ObjSelector::GetChildAnimTable(void) {
    asm volatile(".long 0x9421FFF0\n.long 0x7C0802A6\n.long 0x93E1000C\n.long 0x90010014\n.long 0x7C7F1B78\n.long 0x801F0044\n.long 0x2C000000\n.long 0x4082002C\n.long 0x4BF992C1\n.long 0x907F0044\n.long 0x38A00082\n.long 0x809F0004\n.long 0x81230000\n.long 0xA8090010\n.long 0x81290014\n.long 0x7C630214\n.long 0x7D2803A6\n.long 0x4E800021\n.long 0x807F0044\n.long 0x80010014\n.long 0x7C0803A6\n.long 0x83E1000C\n.long 0x38210010\n.long 0x4E800020");
}
