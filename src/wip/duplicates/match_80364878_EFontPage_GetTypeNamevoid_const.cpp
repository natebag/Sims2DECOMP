// 0x80364878 (12 bytes) - EFontPage::GetTypeName(void) const
// lis r9,upper; lwz r3,lower(r9); blr - return word from global

struct TI_80364878 { int data[4]; };
extern TI_80364878 g_80364878;

struct C_80364878 {
    int fn() const;
};

int C_80364878::fn() const {
    return g_80364878.data[3];
}
