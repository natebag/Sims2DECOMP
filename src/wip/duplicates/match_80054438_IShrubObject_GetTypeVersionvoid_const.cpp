// 0x80054438 (12 bytes) - IShrubObject::GetTypeVersion(void) const
// lis r9,upper; lhz r3,lower(r9); blr - return unsigned short from global

struct TI_80054438 { int data[4]; };
extern TI_80054438 g_80054438;

struct C_80054438 {
    unsigned short fn() const;
};

unsigned short C_80054438::fn() const {
    return *(unsigned short*)&g_80054438.data[3];
}
