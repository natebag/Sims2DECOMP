// MATCH: 0x80089A14 EGameStateMan::EGameStateMan (40 bytes)
// Store order: offset 8, offset 4, offset 12, offset 0, offset 16
// Values: 0, 0, 1, 0, 0

struct EGameStateMan {
    int field_0;
    int field_4;
    int field_8;
    int field_c;
    int field_10;
};

extern "C" void EGameStateMan_ctor(EGameStateMan* this_) {
    // Need exact store order to match
    int* base = (int*)this_;
    base[2] = 0;   // offset 8
    base[1] = 0;   // offset 4
    base[3] = 1;   // offset 12 (0xc)
    base[0] = 0;   // offset 0
    base[4] = 0;   // offset 16
}
