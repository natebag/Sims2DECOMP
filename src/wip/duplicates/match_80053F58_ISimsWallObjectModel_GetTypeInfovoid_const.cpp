// 0x80053F58 (12 bytes) - ISimsWallObjectModel::GetTypeInfo(void) const
// lis r3,upper; addi r3,r3,lower; blr - return global address

struct TI_80053F58 { int data[4]; };
extern TI_80053F58 g_80053F58;

TI_80053F58* fn_80053F58() {
    return &g_80053F58;
}
