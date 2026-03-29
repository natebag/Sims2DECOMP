// 0x80226F1C (12 bytes) - EIAmbLight::GetTypeInfo(void) const
// lis r3,upper; addi r3,r3,lower; blr - return global address

struct TI_80226F1C { int data[4]; };
extern TI_80226F1C g_80226F1C;

TI_80226F1C* fn_80226F1C() {
    return &g_80226F1C;
}
