// 0x8022E0A0 (12 bytes) - EIStaticModel::GetTypeInfoStatic(void)
// lis r3,upper; addi r3,r3,lower; blr - return global address

struct TI_8022E0A0 { int data[4]; };
extern TI_8022E0A0 g_8022E0A0;

TI_8022E0A0* fn_8022E0A0() {
    return &g_8022E0A0;
}
