// 0x80227448 (12 bytes) - EIDirLight::GetTypeInfoStatic(void)
// lis r3,upper; addi r3,r3,lower; blr - return global address

struct TI_80227448 { int data[4]; };
extern TI_80227448 g_80227448;

TI_80227448* fn_80227448() {
    return &g_80227448;
}
