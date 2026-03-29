// 0x80227424 (12 bytes) - EIDirLight::GetTypeName(void) const
// lis r9,upper; lwz r3,lower(r9); blr - return word from global

struct TI_80227424 { int data[4]; };
extern TI_80227424 g_80227424;

struct C_80227424 {
    int fn() const;
};

int C_80227424::fn() const {
    return g_80227424.data[3];
}
