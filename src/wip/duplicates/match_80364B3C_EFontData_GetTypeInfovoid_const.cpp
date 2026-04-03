// 0x80364B3C (12 bytes) - EFontData::GetTypeInfo(void) const
// lis r3,upper; addi r3,r3,lower; blr - return global address

struct TI_80364B3C { int data[4]; };
extern TI_80364B3C g_80364B3C;

TI_80364B3C* fn_80364B3C() {
    return &g_80364B3C;
}
