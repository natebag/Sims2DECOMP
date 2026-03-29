// 0x80368098 (12 bytes) - ERAnim::GetTypeName(void) const
// lis r9,upper; lwz r3,lower(r9); blr - return word from global

struct TI_80368098 { int data[4]; };
extern TI_80368098 g_80368098;

struct C_80368098 {
    int fn() const;
};

int C_80368098::fn() const {
    return g_80368098.data[3];
}
