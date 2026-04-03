// 0x80229C44 (12 bytes) - EIPointAmbLight::GetTypeInfo(void) const
// lis r3,upper; addi r3,r3,lower; blr - return global address

struct TI_80229C44 { int data[4]; };
extern TI_80229C44 g_80229C44;

TI_80229C44* fn_80229C44() {
    return &g_80229C44;
}
