// 0x80368C44 (12 bytes) - ERCharacter::GetTypeInfo(void) const
// lis r3,upper; addi r3,r3,lower; blr - return global address

struct TI_80368C44 { int data[4]; };
extern TI_80368C44 g_80368C44;

TI_80368C44* fn_80368C44() {
    return &g_80368C44;
}
