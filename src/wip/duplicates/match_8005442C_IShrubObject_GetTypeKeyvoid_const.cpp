// 0x8005442C (12 bytes) - IShrubObject::GetTypeKey(void) const
// lis r9,upper; lwz r3,lower(r9); blr - return word from global

struct TI_8005442C { int data[4]; };
extern TI_8005442C g_8005442C;

struct C_8005442C {
    int fn() const;
};

int C_8005442C::fn() const {
    return g_8005442C.data[3];
}
