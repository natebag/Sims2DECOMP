// 0x803680A4 (12 bytes) - ERAnim::GetTypeKey(void) const
// lis r9,upper; lwz r3,lower(r9); blr - return word from global

struct TI_803680A4 { int data[4]; };
extern TI_803680A4 g_803680A4;

struct C_803680A4 {
    int fn() const;
};

int C_803680A4::fn() const {
    return g_803680A4.data[3];
}
