// 0x80229C74 (12 bytes) - EIPointAmbLight::GetTypeInfoStatic(void)
// lis r3,upper; addi r3,r3,lower; blr - return global address

struct TI_80229C74 { int data[4]; };
extern TI_80229C74 g_80229C74;

TI_80229C74* fn_80229C74() {
    return &g_80229C74;
}
