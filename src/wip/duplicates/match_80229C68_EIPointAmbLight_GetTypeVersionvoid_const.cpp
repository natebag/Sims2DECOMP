// 0x80229C68 (12 bytes) - EIPointAmbLight::GetTypeVersion(void) const
// lis r9,upper; lhz r3,lower(r9); blr - return unsigned short from global

struct TI_80229C68 { int data[4]; };
extern TI_80229C68 g_80229C68;

struct C_80229C68 {
    unsigned short fn() const;
};

unsigned short C_80229C68::fn() const {
    return *(unsigned short*)&g_80229C68.data[3];
}
