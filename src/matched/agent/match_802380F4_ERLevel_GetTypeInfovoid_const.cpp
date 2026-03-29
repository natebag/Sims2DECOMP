// 0x802380F4 (12 bytes) - ERLevel::GetTypeInfo(void) const
// lis r3,upper; addi r3,r3,lower; blr - return global address

struct TI_802380F4 { int data[4]; };
extern TI_802380F4 g_802380F4;

TI_802380F4* fn_802380F4() {
    return &g_802380F4;
}
