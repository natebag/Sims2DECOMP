// 0x80054298 (12 bytes) - ISimsCounterTopObject::GetTypeKey(void) const
// lis r9,upper; lwz r3,lower(r9); blr - return word from global

struct TI_80054298 { int data[4]; };
extern TI_80054298 g_80054298;

struct C_80054298 {
    int fn() const;
};

int C_80054298::fn() const {
    return g_80054298.data[3];
}
