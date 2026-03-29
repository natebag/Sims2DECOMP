// 0x8022B044 (12 bytes) - EIPortalPointLight::GetTypeName(void) const
// lis r9,upper; lwz r3,lower(r9); blr - return word from global

struct TI_8022B044 { int data[4]; };
extern TI_8022B044 g_8022B044;

struct C_8022B044 {
    int fn() const;
};

int C_8022B044::fn() const {
    return g_8022B044.data[3];
}
