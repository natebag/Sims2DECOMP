// 0x80229C5C (12 bytes) - EIPointAmbLight::GetTypeKey(void) const
// lis r9,upper; lwz r3,lower(r9); blr - return word from global

struct TI_80229C5C { int data[4]; };
extern TI_80229C5C g_80229C5C;

struct C_80229C5C {
    int fn() const;
};

int C_80229C5C::fn() const {
    return g_80229C5C.data[3];
}
