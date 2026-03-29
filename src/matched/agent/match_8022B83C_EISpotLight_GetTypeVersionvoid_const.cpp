// 0x8022B83C (12 bytes) - EISpotLight::GetTypeVersion(void) const
// lis r9,upper; lhz r3,lower(r9); blr - return unsigned short from global

struct TI_8022B83C { int data[4]; };
extern TI_8022B83C g_8022B83C;

struct C_8022B83C {
    unsigned short fn() const;
};

unsigned short C_8022B83C::fn() const {
    return *(unsigned short*)&g_8022B83C.data[3];
}
