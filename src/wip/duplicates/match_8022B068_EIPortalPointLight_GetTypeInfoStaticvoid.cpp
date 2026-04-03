// 0x8022B068 (12 bytes) - EIPortalPointLight::GetTypeInfoStatic(void)
// lis r3,upper; addi r3,r3,lower; blr - return global address

struct TI_8022B068 { int data[4]; };
extern TI_8022B068 g_8022B068;

TI_8022B068* fn_8022B068() {
    return &g_8022B068;
}
