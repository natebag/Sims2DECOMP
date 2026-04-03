// 0x800542B0 (12 bytes) - ISimsCounterTopObject::GetTypeInfoStatic(void)
// lis r3,upper; addi r3,r3,lower; blr - return global address

struct TI_800542B0 { int data[4]; };
extern TI_800542B0 g_800542B0;

TI_800542B0* fn_800542B0() {
    return &g_800542B0;
}
