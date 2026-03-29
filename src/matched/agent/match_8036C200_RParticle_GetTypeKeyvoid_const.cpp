// 0x8036C200 (12 bytes) - RParticle::GetTypeKey(void) const
// lis r9,upper; lwz r3,lower(r9); blr - return word from global

struct TI_8036C200 { int data[4]; };
extern TI_8036C200 g_8036C200;

struct C_8036C200 {
    int fn() const;
};

int C_8036C200::fn() const {
    return g_8036C200.data[3];
}
