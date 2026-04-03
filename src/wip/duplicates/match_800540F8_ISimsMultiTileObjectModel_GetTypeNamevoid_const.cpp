// 0x800540F8 (12 bytes) - ISimsMultiTileObjectModel::GetTypeName(void) const
// lis r9,upper; lwz r3,lower(r9); blr - return word from global

struct TI_800540F8 { int data[4]; };
extern TI_800540F8 g_800540F8;

struct C_800540F8 {
    int fn() const;
};

int C_800540F8::fn() const {
    return g_800540F8.data[3];
}
