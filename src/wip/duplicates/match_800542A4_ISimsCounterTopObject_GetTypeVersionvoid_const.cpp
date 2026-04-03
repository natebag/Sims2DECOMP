// 0x800542A4 (12 bytes) - ISimsCounterTopObject::GetTypeVersion(void) const
// lis r9,upper; lhz r3,lower(r9); blr - return unsigned short from global

struct TI_800542A4 { int data[4]; };
extern TI_800542A4 g_800542A4;

struct C_800542A4 {
    unsigned short fn() const;
};

unsigned short C_800542A4::fn() const {
    return *(unsigned short*)&g_800542A4.data[3];
}
