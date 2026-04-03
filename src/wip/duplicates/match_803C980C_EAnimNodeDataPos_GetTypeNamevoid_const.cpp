// 0x803C980C (12 bytes) - EAnimNodeDataPos::GetTypeName(void) const
// lis r9,upper; lwz r3,lower(r9); blr - return word from global

struct TI_803C980C { int data[4]; };
extern TI_803C980C g_803C980C;

struct C_803C980C {
    int fn() const;
};

int C_803C980C::fn() const {
    return g_803C980C.data[3];
}
