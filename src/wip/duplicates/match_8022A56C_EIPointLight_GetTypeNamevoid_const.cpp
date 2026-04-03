// 0x8022A56C (12 bytes) - EIPointLight::GetTypeName(void) const
// lis r9,upper; lwz r3,lower(r9); blr - return word from global

struct TI_8022A56C { int data[4]; };
extern TI_8022A56C g_8022A56C;

struct C_8022A56C {
    int fn() const;
};

int C_8022A56C::fn() const {
    return g_8022A56C.data[3];
}
