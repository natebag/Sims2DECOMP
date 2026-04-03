// 0x8022B854 (12 bytes) - EISpotLight::GetReadVersion(void)
// lis r9,upper; lhz r3,lower(r9); blr - return unsigned short from global

struct TI_8022B854 { int data[4]; };
extern TI_8022B854 g_8022B854;

struct C_8022B854 {
    unsigned short fn() const;
};

unsigned short C_8022B854::fn() const {
    return *(unsigned short*)&g_8022B854.data[3];
}
