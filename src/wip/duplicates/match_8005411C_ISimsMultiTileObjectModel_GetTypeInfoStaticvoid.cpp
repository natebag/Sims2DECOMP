// 0x8005411C (12 bytes) - ISimsMultiTileObjectModel::GetTypeInfoStatic(void)
// lis r3,upper; addi r3,r3,lower; blr - return global address

struct TI_8005411C { int data[4]; };
extern TI_8005411C g_8005411C;

TI_8005411C* fn_8005411C() {
    return &g_8005411C;
}
