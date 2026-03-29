// 0x8036B16C (12 bytes) - REffectsSequencer::GetTypeName(void) const
// lis r9,upper; lwz r3,lower(r9); blr - return word from global

struct TI_8036B16C { int data[4]; };
extern TI_8036B16C g_8036B16C;

struct C_8036B16C {
    int fn() const;
};

int C_8036B16C::fn() const {
    return g_8036B16C.data[3];
}
