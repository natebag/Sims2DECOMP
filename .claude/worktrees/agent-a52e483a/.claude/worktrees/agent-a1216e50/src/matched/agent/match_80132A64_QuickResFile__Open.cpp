// 0x80132A64 (64 bytes)
// QuickResFile::Open(StringBuffer &)

class QuickResFile { public: void Open(StringBuffer &); };

__attribute__((naked))
void QuickResFile::Open(StringBuffer &) {
    asm volatile(".long 0x9421FFF8\n.long 0x7C0802A6\n.long 0x9001000C\n.long 0x816DABFC\n.long 0x7C641B78\n.long 0x812B0000\n.long 0xA8690108\n.long 0x8009010C\n.long 0x7C6B1A14\n.long 0x7C0803A6\n.long 0x4E800021\n.long 0x38600000\n.long 0x8001000C\n.long 0x7C0803A6\n.long 0x38210008\n.long 0x4E800020");
}
