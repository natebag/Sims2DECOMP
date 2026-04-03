// 0x80368574 (12 bytes) - ERBinary::GetTypeVersion(void) const
// lis r9,upper; lhz r3,lower(r9); blr - return unsigned short from global

struct TI_80368574 { int data[4]; };
extern TI_80368574 g_80368574;

struct C_80368574 {
    unsigned short fn() const;
};

unsigned short C_80368574::fn() const {
    return *(unsigned short*)&g_80368574.data[3];
}
