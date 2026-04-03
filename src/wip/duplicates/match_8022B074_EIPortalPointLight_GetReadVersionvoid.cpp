// 0x8022B074 (12 bytes) - EIPortalPointLight::GetReadVersion(void)
// lis r9,upper; lhz r3,lower(r9); blr - return unsigned short from global

struct TI_8022B074 { int data[4]; };
extern TI_8022B074 g_8022B074;

struct C_8022B074 {
    unsigned short fn() const;
};

unsigned short C_8022B074::fn() const {
    return *(unsigned short*)&g_8022B074.data[3];
}
