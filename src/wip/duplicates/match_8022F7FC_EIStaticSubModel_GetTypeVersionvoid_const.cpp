// 0x8022F7FC (12 bytes) - EIStaticSubModel::GetTypeVersion(void) const
// lis r9,upper; lhz r3,lower(r9); blr - return unsigned short from global

struct TI_8022F7FC { int data[4]; };
extern TI_8022F7FC g_8022F7FC;

struct C_8022F7FC {
    unsigned short fn() const;
};

unsigned short C_8022F7FC::fn() const {
    return *(unsigned short*)&g_8022F7FC.data[3];
}
