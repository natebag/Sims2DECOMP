// 0x80227430 (12 bytes) - EIDirLight::GetTypeKey(void) const
// lis r9,upper; lwz r3,lower(r9); blr - return word from global

struct TI_80227430 { int data[4]; };
extern TI_80227430 g_80227430;

struct C_80227430 {
    int fn() const;
};

int C_80227430::fn() const {
    return g_80227430.data[3];
}
