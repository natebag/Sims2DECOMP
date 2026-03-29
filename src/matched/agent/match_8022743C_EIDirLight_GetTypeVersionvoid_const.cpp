// 0x8022743C (12 bytes) - EIDirLight::GetTypeVersion(void) const
// lis r9,upper; lhz r3,lower(r9); blr - return unsigned short from global

struct TI_8022743C { int data[4]; };
extern TI_8022743C g_8022743C;

struct C_8022743C {
    unsigned short fn() const;
};

unsigned short C_8022743C::fn() const {
    return *(unsigned short*)&g_8022743C.data[3];
}
