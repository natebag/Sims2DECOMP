// 0x80135850 (88 bytes)
// iResFile::GetByIDAndLanguage(int, short, char, void (*)(void *, int))

class iResFile { public: void GetByIDAndLanguage(int, short, char, void (*)(void *, int)); };

__attribute__((naked))
void iResFile::GetByIDAndLanguage(int, short, char, void (*)(void *, int)) {
    asm volatile(".long 0x9421FFF8\n.long 0x7C0802A6\n.long 0x9001000C\n.long 0x7C6B1B78\n.long 0x2C060000\n.long 0x40820024\n.long 0x812B000C\n.long 0x7CE63B78\n.long 0xA8690080\n.long 0x80090084\n.long 0x7C6B1A14\n.long 0x7C0803A6\n.long 0x4E800021\n.long 0x48000014\n.long 0x7D635B78\n.long 0x3880FFA5\n.long 0x4BFFFD9D\n.long 0x38600000\n.long 0x8001000C\n.long 0x7C0803A6\n.long 0x38210008\n.long 0x4E800020");
}
