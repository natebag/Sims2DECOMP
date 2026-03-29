// 0x8022F7F0 (12 bytes) - EIStaticSubModel::GetTypeKey(void) const
// lis r9,upper; lwz r3,lower(r9); blr - return word from global

struct TI_8022F7F0 { int data[4]; };
extern TI_8022F7F0 g_8022F7F0;

struct C_8022F7F0 {
    int fn() const;
};

int C_8022F7F0::fn() const {
    return g_8022F7F0.data[3];
}
