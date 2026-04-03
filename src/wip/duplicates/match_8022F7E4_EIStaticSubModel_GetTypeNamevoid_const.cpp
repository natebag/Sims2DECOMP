// 0x8022F7E4 (12 bytes) - EIStaticSubModel::GetTypeName(void) const
// lis r9,upper; lwz r3,lower(r9); blr - return word from global

struct TI_8022F7E4 { int data[4]; };
extern TI_8022F7E4 g_8022F7E4;

struct C_8022F7E4 {
    int fn() const;
};

int C_8022F7E4::fn() const {
    return g_8022F7E4.data[3];
}
