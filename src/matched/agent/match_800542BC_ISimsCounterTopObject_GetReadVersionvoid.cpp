// 0x800542BC (12 bytes) - ISimsCounterTopObject::GetReadVersion(void)
// lis r9,upper; lhz r3,lower(r9); blr - return unsigned short from global

struct TI_800542BC { int data[4]; };
extern TI_800542BC g_800542BC;

struct C_800542BC {
    unsigned short fn() const;
};

unsigned short C_800542BC::fn() const {
    return *(unsigned short*)&g_800542BC.data[3];
}
