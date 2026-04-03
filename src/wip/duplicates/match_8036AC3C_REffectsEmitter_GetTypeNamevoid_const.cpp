// 0x8036AC3C (12 bytes) - REffectsEmitter::GetTypeName(void) const
// lis r9,upper; lwz r3,lower(r9); blr - return word from global

struct TI_8036AC3C { int data[4]; };
extern TI_8036AC3C g_8036AC3C;

struct C_8036AC3C {
    int fn() const;
};

int C_8036AC3C::fn() const {
    return g_8036AC3C.data[3];
}
