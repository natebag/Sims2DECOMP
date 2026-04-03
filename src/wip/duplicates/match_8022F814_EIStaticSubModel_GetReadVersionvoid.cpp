// 0x8022F814 (12 bytes) - EIStaticSubModel::GetReadVersion(void)
// lis r9,upper; lhz r3,lower(r9); blr - return unsigned short from global

struct TI_8022F814 { int data[4]; };
extern TI_8022F814 g_8022F814;

struct C_8022F814 {
    unsigned short fn() const;
};

unsigned short C_8022F814::fn() const {
    return *(unsigned short*)&g_8022F814.data[3];
}
