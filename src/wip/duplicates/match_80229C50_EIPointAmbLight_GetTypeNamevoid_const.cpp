// 0x80229C50 (12 bytes) - EIPointAmbLight::GetTypeName(void) const
// lis r9,upper; lwz r3,lower(r9); blr - return word from global

struct TI_80229C50 { int data[4]; };
extern TI_80229C50 g_80229C50;

struct C_80229C50 {
    int fn() const;
};

int C_80229C50::fn() const {
    return g_80229C50.data[3];
}
