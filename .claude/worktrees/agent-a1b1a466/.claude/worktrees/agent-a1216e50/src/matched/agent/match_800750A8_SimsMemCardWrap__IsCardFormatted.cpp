// 0x800750A8 (64 bytes)
// SimsMemCardWrap::IsCardFormatted(int, bool &)

class SimsMemCardWrap { public: void IsCardFormatted(int, bool &); };

__attribute__((naked))
void SimsMemCardWrap::IsCardFormatted(int, bool &) {
    asm volatile(".long 0x9421FFF8\n.long 0x7C0802A6\n.long 0x9001000C\n.long 0x816D98F0\n.long 0x7C852378\n.long 0x7C641B78\n.long 0x812B0000\n.long 0xA86900B0\n.long 0x800900B4\n.long 0x7C6B1A14\n.long 0x7C0803A6\n.long 0x4E800021\n.long 0x8001000C\n.long 0x7C0803A6\n.long 0x38210008\n.long 0x4E800020");
}
