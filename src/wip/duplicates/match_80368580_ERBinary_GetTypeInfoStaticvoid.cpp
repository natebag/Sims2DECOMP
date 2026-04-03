// 0x80368580 (12 bytes) - ERBinary::GetTypeInfoStatic(void)
// lis r3,upper; addi r3,r3,lower; blr - return global address

struct TI_80368580 { int data[4]; };
extern TI_80368580 g_80368580;

TI_80368580* fn_80368580() {
    return &g_80368580;
}
