// 0x803680B0 (12 bytes) - ERAnim::GetTypeVersion(void) const
// lis r9,upper; lhz r3,lower(r9); blr - return unsigned short from global

struct TI_803680B0 { int data[4]; };
extern TI_803680B0 g_803680B0;

struct C_803680B0 {
    unsigned short fn() const;
};

unsigned short C_803680B0::fn() const {
    return *(unsigned short*)&g_803680B0.data[3];
}
