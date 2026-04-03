// 0x80367248 (12 bytes) - ERAmbientScore::GetTypeVersion(void) const
// lis r9,upper; lhz r3,lower(r9); blr - return unsigned short from global

struct TI_80367248 { int data[4]; };
extern TI_80367248 g_80367248;

struct C_80367248 {
    unsigned short fn() const;
};

unsigned short C_80367248::fn() const {
    return *(unsigned short*)&g_80367248.data[3];
}
