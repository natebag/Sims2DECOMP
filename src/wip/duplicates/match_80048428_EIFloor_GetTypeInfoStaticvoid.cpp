// 0x80048428 (12 bytes) - EIFloor::GetTypeInfoStatic(void)
// lis r3,upper; addi r3,r3,lower; blr - return global address

struct TI_80048428 { int data[4]; };
extern TI_80048428 g_80048428;

TI_80048428* fn_80048428() {
    return &g_80048428;
}
