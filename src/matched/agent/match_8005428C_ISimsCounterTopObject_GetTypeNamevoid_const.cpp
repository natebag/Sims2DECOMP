// 0x8005428C (12 bytes) - ISimsCounterTopObject::GetTypeName(void) const
// lis r9,upper; lwz r3,lower(r9); blr - return word from global

struct TI_8005428C { int data[4]; };
extern TI_8005428C g_8005428C;

struct C_8005428C {
    int fn() const;
};

int C_8005428C::fn() const {
    return g_8005428C.data[3];
}
