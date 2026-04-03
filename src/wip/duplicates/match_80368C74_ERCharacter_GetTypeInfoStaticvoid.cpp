// 0x80368C74 (12 bytes) - ERCharacter::GetTypeInfoStatic(void)
// lis r3,upper; addi r3,r3,lower; blr - return global address

struct TI_80368C74 { int data[4]; };
extern TI_80368C74 g_80368C74;

TI_80368C74* fn_80368C74() {
    return &g_80368C74;
}
