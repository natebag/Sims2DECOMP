// 0x800483F8 (12 bytes) - EIFloor::GetTypeInfo(void) const
// lis r3,upper; addi r3,r3,lower; blr - return global address

struct TI_800483F8 { int data[4]; };
extern TI_800483F8 g_800483F8;

TI_800483F8* fn_800483F8() {
    return &g_800483F8;
}
