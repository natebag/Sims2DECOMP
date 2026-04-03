// 0x80364B6C (12 bytes) - EFontData::GetTypeInfoStatic(void)
// lis r3,upper; addi r3,r3,lower; blr - return global address

struct TI_80364B6C { int data[4]; };
extern TI_80364B6C g_80364B6C;

TI_80364B6C* fn_80364B6C() {
    return &g_80364B6C;
}
