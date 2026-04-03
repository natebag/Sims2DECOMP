// 0x8036B190 (12 bytes) - REffectsSequencer::GetTypeInfoStatic(void)
// lis r3,upper; addi r3,r3,lower; blr - return global address

struct TI_8036B190 { int data[4]; };
extern TI_8036B190 g_8036B190;

TI_8036B190* fn_8036B190() {
    return &g_8036B190;
}
