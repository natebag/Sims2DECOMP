// 0x80074FB8 (80 bytes)
// SimsMemCardWrap::IsPolledCardInSlot(int, bool &)

class SimsMemCardWrap { public: void IsPolledCardInSlot(int, bool &); };

__attribute__((naked))
void SimsMemCardWrap::IsPolledCardInSlot(int, bool &) {
    asm volatile(".long 0x9421FFF0\n.long 0x7C0802A6\n.long 0xBFC10008\n.long 0x90010014\n.long 0x816D98F0\n.long 0x7C9E2378\n.long 0x7C641B78\n.long 0x812B0000\n.long 0xA8690098\n.long 0x8009009C\n.long 0x7C6B1A14\n.long 0x7C0803A6\n.long 0x4E800021\n.long 0x907E0000\n.long 0x38600001\n.long 0x80010014\n.long 0x7C0803A6\n.long 0xBBC10008\n.long 0x38210010\n.long 0x4E800020");
}
