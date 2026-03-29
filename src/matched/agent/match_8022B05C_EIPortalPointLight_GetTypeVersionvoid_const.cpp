// 0x8022B05C (12 bytes) - EIPortalPointLight::GetTypeVersion(void) const
// lis r9,upper; lhz r3,lower(r9); blr - return unsigned short from global

struct TI_8022B05C { int data[4]; };
extern TI_8022B05C g_8022B05C;

struct C_8022B05C {
    unsigned short fn() const;
};

unsigned short C_8022B05C::fn() const {
    return *(unsigned short*)&g_8022B05C.data[3];
}
