// 0x80364718 (12 bytes) - EFontCharacter::GetTypeInfo(void) const
// lis r3,upper; addi r3,r3,lower; blr - return global address

struct TI_80364718 { int data[4]; };
extern TI_80364718 g_80364718;

TI_80364718* fn_80364718() {
    return &g_80364718;
}
