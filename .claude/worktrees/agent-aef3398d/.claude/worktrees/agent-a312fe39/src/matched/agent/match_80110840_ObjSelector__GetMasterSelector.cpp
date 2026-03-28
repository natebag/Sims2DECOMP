// 0x80110840 (92 bytes)
// ObjSelector::GetMasterSelector(void)

class ObjSelector { public: void GetMasterSelector(void); };

__attribute__((naked))
void ObjSelector::GetMasterSelector(void) {
    asm volatile(".long 0x9421FFF0\n.long 0x7C0802A6\n.long 0x93E1000C\n.long 0x90010014\n.long 0x7C7F1B78\n.long 0x801F0060\n.long 0x2C000000\n.long 0x40820028\n.long 0x807F0050\n.long 0x7FE4FB78\n.long 0x81230000\n.long 0xA80900A0\n.long 0x812900A4\n.long 0x7C630214\n.long 0x7D2803A6\n.long 0x4E800021\n.long 0x907F0060\n.long 0x807F0060\n.long 0x80010014\n.long 0x7C0803A6\n.long 0x83E1000C\n.long 0x38210010\n.long 0x4E800020");
}
