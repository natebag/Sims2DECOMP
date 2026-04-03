// 0x8036C20C (12 bytes) - RParticle::GetTypeVersion(void) const
// lis r9,upper; lhz r3,lower(r9); blr - return unsigned short from global

struct TI_8036C20C { int data[4]; };
extern TI_8036C20C g_8036C20C;

struct C_8036C20C {
    unsigned short fn() const;
};

unsigned short C_8036C20C::fn() const {
    return *(unsigned short*)&g_8036C20C.data[3];
}
