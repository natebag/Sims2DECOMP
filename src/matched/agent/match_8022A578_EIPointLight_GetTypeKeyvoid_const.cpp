// 0x8022A578 (12 bytes) - EIPointLight::GetTypeKey(void) const
// lis r9,upper; lwz r3,lower(r9); blr - return word from global

struct TI_8022A578 { int data[4]; };
extern TI_8022A578 g_8022A578;

struct C_8022A578 {
    int fn() const;
};

int C_8022A578::fn() const {
    return g_8022A578.data[3];
}
