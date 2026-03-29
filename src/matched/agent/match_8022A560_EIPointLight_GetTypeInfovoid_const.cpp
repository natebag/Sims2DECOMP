// 0x8022A560 (12 bytes) - EIPointLight::GetTypeInfo(void) const
// lis r3,upper; addi r3,r3,lower; blr - return global address

struct TI_8022A560 { int data[4]; };
extern TI_8022A560 g_8022A560;

TI_8022A560* fn_8022A560() {
    return &g_8022A560;
}
