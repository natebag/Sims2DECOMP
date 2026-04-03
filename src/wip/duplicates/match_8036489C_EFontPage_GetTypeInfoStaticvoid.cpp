// 0x8036489C (12 bytes) - EFontPage::GetTypeInfoStatic(void)
// lis r3,upper; addi r3,r3,lower; blr - return global address

struct TI_8036489C { int data[4]; };
extern TI_8036489C g_8036489C;

TI_8036489C* fn_8036489C() {
    return &g_8036489C;
}
