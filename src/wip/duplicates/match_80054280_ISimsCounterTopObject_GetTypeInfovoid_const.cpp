// 0x80054280 (12 bytes) - ISimsCounterTopObject::GetTypeInfo(void) const
// lis r3,upper; addi r3,r3,lower; blr - return global address

struct TI_80054280 { int data[4]; };
extern TI_80054280 g_80054280;

TI_80054280* fn_80054280() {
    return &g_80054280;
}
