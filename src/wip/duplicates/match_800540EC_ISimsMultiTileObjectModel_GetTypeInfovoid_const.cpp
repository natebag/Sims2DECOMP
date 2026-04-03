// 0x800540EC (12 bytes) - ISimsMultiTileObjectModel::GetTypeInfo(void) const
// lis r3,upper; addi r3,r3,lower; blr - return global address

struct TI_800540EC { int data[4]; };
extern TI_800540EC g_800540EC;

TI_800540EC* fn_800540EC() {
    return &g_800540EC;
}
