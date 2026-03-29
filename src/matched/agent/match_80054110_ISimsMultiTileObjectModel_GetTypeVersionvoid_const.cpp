// 0x80054110 (12 bytes) - ISimsMultiTileObjectModel::GetTypeVersion(void) const
// lis r9,upper; lhz r3,lower(r9); blr - return unsigned short from global

struct TI_80054110 { int data[4]; };
extern TI_80054110 g_80054110;

struct C_80054110 {
    unsigned short fn() const;
};

unsigned short C_80054110::fn() const {
    return *(unsigned short*)&g_80054110.data[3];
}
