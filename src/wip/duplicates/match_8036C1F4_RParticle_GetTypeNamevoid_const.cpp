// 0x8036C1F4 (12 bytes) - RParticle::GetTypeName(void) const
// lis r9,upper; lwz r3,lower(r9); blr - return word from global

struct TI_8036C1F4 { int data[4]; };
extern TI_8036C1F4 g_8036C1F4;

struct C_8036C1F4 {
    int fn() const;
};

int C_8036C1F4::fn() const {
    return g_8036C1F4.data[3];
}
