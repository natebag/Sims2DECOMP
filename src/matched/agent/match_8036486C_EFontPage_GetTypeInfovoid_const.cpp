// 0x8036486C (12 bytes) - EFontPage::GetTypeInfo(void) const
// lis r3,upper; addi r3,r3,lower; blr - return global address

struct TI_8036486C { int data[4]; };
extern TI_8036486C g_8036486C;

TI_8036486C* fn_8036486C() {
    return &g_8036486C;
}
