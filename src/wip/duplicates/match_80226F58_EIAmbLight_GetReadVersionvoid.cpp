// 0x80226F58 (12 bytes) - EIAmbLight::GetReadVersion(void)
// lis r9,upper; lhz r3,lower(r9); blr - return unsigned short from global

struct TI_80226F58 { int data[4]; };
extern TI_80226F58 g_80226F58;

struct C_80226F58 {
    unsigned short fn() const;
};

unsigned short C_80226F58::fn() const {
    return *(unsigned short*)&g_80226F58.data[3];
}
