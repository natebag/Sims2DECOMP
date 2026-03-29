// 0x80054104 (12 bytes) - ISimsMultiTileObjectModel::GetTypeKey(void) const
// lis r9,upper; lwz r3,lower(r9); blr - return word from global

struct TI_80054104 { int data[4]; };
extern TI_80054104 g_80054104;

struct C_80054104 {
    int fn() const;
};

int C_80054104::fn() const {
    return g_80054104.data[3];
}
