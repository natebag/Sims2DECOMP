// 0x80226F34 (12 bytes) - EIAmbLight::GetTypeKey(void) const
// lis r9,upper; lwz r3,lower(r9); blr - return word from global

struct TI_80226F34 { int data[4]; };
extern TI_80226F34 g_80226F34;

struct C_80226F34 {
    int fn() const;
};

int C_80226F34::fn() const {
    return g_80226F34.data[3];
}
