// 0x80368550 (12 bytes) - ERBinary::GetTypeInfo(void) const
// lis r3,upper; addi r3,r3,lower; blr - return global address

struct TI_80368550 { int data[4]; };
extern TI_80368550 g_80368550;

TI_80368550* fn_80368550() {
    return &g_80368550;
}
