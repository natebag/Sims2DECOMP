// 0x8016B8BC (84 bytes)
// CasSimPartsS2C::GetTextureIDFromVector(VECTOR<unsigned int> &, int, bool, unsigned char, char *) const

class CasSimPartsS2C { public: void GetTextureIDFromVector(VECTOR<unsigned int> &, int, bool, unsigned char, char *) const; };

__attribute__((naked))
void CasSimPartsS2C::GetTextureIDFromVector(VECTOR<unsigned int> &, int, bool, unsigned char, char *) const {
    asm volatile(".long 0x80840000\n.long 0x38000000\n.long 0x2F840000\n.long 0x419E0008\n.long 0x8004FFFC\n.long 0x7C002800\n.long 0x41810028\n.long 0x2C060000\n.long 0x4182002C\n.long 0x39200000\n.long 0x419E0008\n.long 0x8124FFFC\n.long 0x7C054800\n.long 0x41800018\n.long 0x38600000\n.long 0x4E800020\n.long 0x54A9103A\n.long 0x7C64482E\n.long 0x4E800020\n.long 0x38600000\n.long 0x4E800020");
}
