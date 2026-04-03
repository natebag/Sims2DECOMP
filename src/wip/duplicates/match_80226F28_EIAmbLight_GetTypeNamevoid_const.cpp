// 0x80226F28 (12 bytes) - EIAmbLight::GetTypeName(void) const
// lis r9,upper; lwz r3,lower(r9); blr - return word from global

struct TI_80226F28 { int data[4]; };
extern TI_80226F28 g_80226F28;

struct C_80226F28 {
    int fn() const;
};

int C_80226F28::fn() const {
    return g_80226F28.data[3];
}
