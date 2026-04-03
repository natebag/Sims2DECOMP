// 0x8022B050 (12 bytes) - EIPortalPointLight::GetTypeKey(void) const
// lis r9,upper; lwz r3,lower(r9); blr - return word from global

struct TI_8022B050 { int data[4]; };
extern TI_8022B050 g_8022B050;

struct C_8022B050 {
    int fn() const;
};

int C_8022B050::fn() const {
    return g_8022B050.data[3];
}
