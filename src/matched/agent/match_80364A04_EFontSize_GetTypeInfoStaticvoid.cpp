// 0x80364A04 (12 bytes) - EFontSize::GetTypeInfoStatic(void)
// lis r3,upper; addi r3,r3,lower; blr - return global address

struct TI_80364A04 { int data[4]; };
extern TI_80364A04 g_80364A04;

TI_80364A04* fn_80364A04() {
    return &g_80364A04;
}
