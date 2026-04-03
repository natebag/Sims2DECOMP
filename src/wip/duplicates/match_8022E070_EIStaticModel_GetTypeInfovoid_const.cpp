// 0x8022E070 (12 bytes) - EIStaticModel::GetTypeInfo(void) const
// lis r3,upper; addi r3,r3,lower; blr - return global address

struct TI_8022E070 { int data[4]; };
extern TI_8022E070 g_8022E070;

TI_8022E070* fn_8022E070() {
    return &g_8022E070;
}
