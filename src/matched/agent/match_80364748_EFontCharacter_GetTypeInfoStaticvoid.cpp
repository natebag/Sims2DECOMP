// 0x80364748 (12 bytes) - EFontCharacter::GetTypeInfoStatic(void)
// lis r3,upper; addi r3,r3,lower; blr - return global address

struct TI_80364748 { int data[4]; };
extern TI_80364748 g_80364748;

TI_80364748* fn_80364748() {
    return &g_80364748;
}
