// 0x800751B4 (68 bytes)
// SimsMemCardWrap::HasSavedGame(int, bool &, int)

class SimsMemCardWrap { public: void HasSavedGame(int, bool &, int); };

__attribute__((naked))
void SimsMemCardWrap::HasSavedGame(int, bool &, int) {
    asm volatile(".long 0x9421FFF8\n.long 0x7C0802A6\n.long 0x9001000C\n.long 0x816D98F0\n.long 0x7C651B78\n.long 0x7C862378\n.long 0x812B0000\n.long 0x808D8344\n.long 0xA86900C8\n.long 0x800900CC\n.long 0x7C6B1A14\n.long 0x7C0803A6\n.long 0x4E800021\n.long 0x8001000C\n.long 0x7C0803A6\n.long 0x38210008\n.long 0x4E800020");
}
