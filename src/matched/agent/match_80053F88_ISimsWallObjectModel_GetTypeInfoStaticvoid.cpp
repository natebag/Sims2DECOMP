// 0x80053F88 (12 bytes) - ISimsWallObjectModel::GetTypeInfoStatic(void)
// lis r3,upper; addi r3,r3,lower; blr - return global address

struct TI_80053F88 { int data[4]; };
extern TI_80053F88 g_80053F88;

TI_80053F88* fn_80053F88() {
    return &g_80053F88;
}
