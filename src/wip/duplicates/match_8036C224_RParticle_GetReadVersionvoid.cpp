// 0x8036C224 (12 bytes) - RParticle::GetReadVersion(void)
// lis r9,upper; lhz r3,lower(r9); blr - return unsigned short from global

struct TI_8036C224 { int data[4]; };
extern TI_8036C224 g_8036C224;

struct C_8036C224 {
    unsigned short fn() const;
};

unsigned short C_8036C224::fn() const {
    return *(unsigned short*)&g_8036C224.data[3];
}
