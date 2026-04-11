// 0x800BCD04 GetLanguage (8B)
// DOL: srawi r3,r3,8 ; blr
// Returns input >> 8 (signed arithmetic shift)

extern "C" int GetLanguage(int x) {
    return x >> 8;
}
