// 0x8036855C (12 bytes) - ERBinary::GetTypeName(void) const
// lis r9,upper; lwz r3,lower(r9); blr - return word from global

struct TI_8036855C { int data[4]; };
extern TI_8036855C g_8036855C;

struct C_8036855C {
    int fn() const;
};

int C_8036855C::fn() const {
    return g_8036855C.data[3];
}
