// 0x803649EC (12 bytes) - EFontSize::GetTypeKey(void) const
// lis r9,upper; lwz r3,lower(r9); blr - return word from global

struct TI_803649EC { int data[4]; };
extern TI_803649EC g_803649EC;

struct C_803649EC {
    int fn() const;
};

int C_803649EC::fn() const {
    return g_803649EC.data[3];
}
