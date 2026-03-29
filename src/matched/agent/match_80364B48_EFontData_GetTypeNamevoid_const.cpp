// 0x80364B48 (12 bytes) - EFontData::GetTypeName(void) const
// lis r9,upper; lwz r3,lower(r9); blr - return word from global

struct TI_80364B48 { int data[4]; };
extern TI_80364B48 g_80364B48;

struct C_80364B48 {
    int fn() const;
};

int C_80364B48::fn() const {
    return g_80364B48.data[3];
}
