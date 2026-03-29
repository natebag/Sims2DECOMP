// 0x8036984C (12 bytes) - ERDataset::GetTypeKey(void) const
// lis r9,upper; lwz r3,lower(r9); blr - return word from global

struct TI_8036984C { int data[4]; };
extern TI_8036984C g_8036984C;

struct C_8036984C {
    int fn() const;
};

int C_8036984C::fn() const {
    return g_8036984C.data[3];
}
