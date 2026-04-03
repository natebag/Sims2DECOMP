// 0x80226F4C (12 bytes) - EIAmbLight::GetTypeInfoStatic(void)
// lis r3,upper; addi r3,r3,lower; blr - return global address

struct TI_80226F4C { int data[4]; };
extern TI_80226F4C g_80226F4C;

TI_80226F4C* fn_80226F4C() {
    return &g_80226F4C;
}
