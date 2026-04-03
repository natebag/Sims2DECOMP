// 0x80364884 (12 bytes) - EFontPage::GetTypeKey(void) const
// lis r9,upper; lwz r3,lower(r9); blr - return word from global

struct TI_80364884 { int data[4]; };
extern TI_80364884 g_80364884;

struct C_80364884 {
    int fn() const;
};

int C_80364884::fn() const {
    return g_80364884.data[3];
}
