// 0x80364B54 (12 bytes) - EFontData::GetTypeKey(void) const
// lis r9,upper; lwz r3,lower(r9); blr - return word from global

struct TI_80364B54 { int data[4]; };
extern TI_80364B54 g_80364B54;

struct C_80364B54 {
    int fn() const;
};

int C_80364B54::fn() const {
    return g_80364B54.data[3];
}
