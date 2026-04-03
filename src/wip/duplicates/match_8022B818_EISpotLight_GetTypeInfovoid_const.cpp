// 0x8022B818 (12 bytes) - EISpotLight::GetTypeInfo(void) const
// lis r3,upper; addi r3,r3,lower; blr - return global address

struct TI_8022B818 { int data[4]; };
extern TI_8022B818 g_8022B818;

TI_8022B818* fn_8022B818() {
    return &g_8022B818;
}
