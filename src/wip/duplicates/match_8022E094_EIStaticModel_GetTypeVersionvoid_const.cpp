// 0x8022E094 (12 bytes) - EIStaticModel::GetTypeVersion(void) const
// lis r9,upper; lhz r3,lower(r9); blr - return unsigned short from global

struct TI_8022E094 { int data[4]; };
extern TI_8022E094 g_8022E094;

struct C_8022E094 {
    unsigned short fn() const;
};

unsigned short C_8022E094::fn() const {
    return *(unsigned short*)&g_8022E094.data[3];
}
