// 0x803649E0 (12 bytes) - EFontSize::GetTypeName(void) const
// lis r9,upper; lwz r3,lower(r9); blr - return word from global

struct TI_803649E0 { int data[4]; };
extern TI_803649E0 g_803649E0;

struct C_803649E0 {
    int fn() const;
};

int C_803649E0::fn() const {
    return g_803649E0.data[3];
}
