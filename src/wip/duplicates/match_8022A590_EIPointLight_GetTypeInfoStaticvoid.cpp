// 0x8022A590 (12 bytes) - EIPointLight::GetTypeInfoStatic(void)
// lis r3,upper; addi r3,r3,lower; blr - return global address

struct TI_8022A590 { int data[4]; };
extern TI_8022A590 g_8022A590;

TI_8022A590* fn_8022A590() {
    return &g_8022A590;
}
