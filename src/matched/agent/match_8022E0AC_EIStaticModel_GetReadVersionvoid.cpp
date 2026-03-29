// 0x8022E0AC (12 bytes) - EIStaticModel::GetReadVersion(void)
// lis r9,upper; lhz r3,lower(r9); blr - return unsigned short from global

struct TI_8022E0AC { int data[4]; };
extern TI_8022E0AC g_8022E0AC;

struct C_8022E0AC {
    unsigned short fn() const;
};

unsigned short C_8022E0AC::fn() const {
    return *(unsigned short*)&g_8022E0AC.data[3];
}
