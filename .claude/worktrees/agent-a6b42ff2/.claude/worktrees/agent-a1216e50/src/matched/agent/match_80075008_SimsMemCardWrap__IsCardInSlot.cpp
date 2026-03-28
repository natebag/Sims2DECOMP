// 0x80075008 (80 bytes)
// SimsMemCardWrap::IsCardInSlot(int, bool &)

class SimsMemCardWrap { public: void IsCardInSlot(int, bool &); };

__attribute__((naked))
void SimsMemCardWrap::IsCardInSlot(int, bool &) {
    asm volatile(".long 0x9421FFF0\n.long 0x7C0802A6\n.long 0xBFC10008\n.long 0x90010014\n.long 0x816D98F0\n.long 0x7C9E2378\n.long 0x7C641B78\n.long 0x812B0000\n.long 0xA86900A0\n.long 0x800900A4\n.long 0x7C6B1A14\n.long 0x7C0803A6\n.long 0x4E800021\n.long 0x907E0000\n.long 0x38600001\n.long 0x80010014\n.long 0x7C0803A6\n.long 0xBBC10008\n.long 0x38210010\n.long 0x4E800020");
}
