// 0x80054128 (12 bytes) - ISimsMultiTileObjectModel::GetReadVersion(void)
// lis r9,upper; lhz r3,lower(r9); blr - return unsigned short from global

struct TI_80054128 { int data[4]; };
extern TI_80054128 g_80054128;

struct C_80054128 {
    unsigned short fn() const;
};

unsigned short C_80054128::fn() const {
    return *(unsigned short*)&g_80054128.data[3];
}
