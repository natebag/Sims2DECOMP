// 0x8023810C (12 bytes) - ERLevel::GetTypeKey(void) const
// lis r9,upper; lwz r3,lower(r9); blr - return word from global

struct TI_8023810C { int data[4]; };
extern TI_8023810C g_8023810C;

struct C_8023810C {
    int fn() const;
};

int C_8023810C::fn() const {
    return g_8023810C.data[3];
}
