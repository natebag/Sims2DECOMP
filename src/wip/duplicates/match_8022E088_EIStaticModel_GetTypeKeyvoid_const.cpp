// 0x8022E088 (12 bytes) - EIStaticModel::GetTypeKey(void) const
// lis r9,upper; lwz r3,lower(r9); blr - return word from global

struct TI_8022E088 { int data[4]; };
extern TI_8022E088 g_8022E088;

struct C_8022E088 {
    int fn() const;
};

int C_8022E088::fn() const {
    return g_8022E088.data[3];
}
