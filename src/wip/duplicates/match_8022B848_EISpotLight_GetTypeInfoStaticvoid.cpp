// 0x8022B848 (12 bytes) - EISpotLight::GetTypeInfoStatic(void)
// lis r3,upper; addi r3,r3,lower; blr - return global address

struct TI_8022B848 { int data[4]; };
extern TI_8022B848 g_8022B848;

TI_8022B848* fn_8022B848() {
    return &g_8022B848;
}
