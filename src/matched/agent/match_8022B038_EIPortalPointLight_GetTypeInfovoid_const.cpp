// 0x8022B038 (12 bytes) - EIPortalPointLight::GetTypeInfo(void) const
// lis r3,upper; addi r3,r3,lower; blr - return global address

struct TI_8022B038 { int data[4]; };
extern TI_8022B038 g_8022B038;

TI_8022B038* fn_8022B038() {
    return &g_8022B038;
}
