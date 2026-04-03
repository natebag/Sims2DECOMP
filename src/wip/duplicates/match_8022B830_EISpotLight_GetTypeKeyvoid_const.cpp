// 0x8022B830 (12 bytes) - EISpotLight::GetTypeKey(void) const
// lis r9,upper; lwz r3,lower(r9); blr - return word from global

struct TI_8022B830 { int data[4]; };
extern TI_8022B830 g_8022B830;

struct C_8022B830 {
    int fn() const;
};

int C_8022B830::fn() const {
    return g_8022B830.data[3];
}
