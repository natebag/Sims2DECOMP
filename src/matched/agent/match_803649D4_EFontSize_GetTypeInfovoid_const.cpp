// 0x803649D4 (12 bytes) - EFontSize::GetTypeInfo(void) const
// lis r3,upper; addi r3,r3,lower; blr - return global address

struct TI_803649D4 { int data[4]; };
extern TI_803649D4 g_803649D4;

TI_803649D4* fn_803649D4() {
    return &g_803649D4;
}
