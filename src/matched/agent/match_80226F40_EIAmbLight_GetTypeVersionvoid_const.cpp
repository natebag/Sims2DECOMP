// 0x80226F40 (12 bytes) - EIAmbLight::GetTypeVersion(void) const
// lis r9,upper; lhz r3,lower(r9); blr - return unsigned short from global

struct TI_80226F40 { int data[4]; };
extern TI_80226F40 g_80226F40;

struct C_80226F40 {
    unsigned short fn() const;
};

unsigned short C_80226F40::fn() const {
    return *(unsigned short*)&g_80226F40.data[3];
}
