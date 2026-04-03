// 0x803C9800 (12 bytes) - EAnimNodeDataPos::GetTypeInfo(void) const
// lis r3,upper; addi r3,r3,lower; blr - return global address

struct TI_803C9800 { int data[4]; };
extern TI_803C9800 g_803C9800;

TI_803C9800* fn_803C9800() {
    return &g_803C9800;
}
