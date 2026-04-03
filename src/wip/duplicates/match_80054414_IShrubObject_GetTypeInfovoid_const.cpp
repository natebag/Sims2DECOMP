// 0x80054414 (12 bytes) - IShrubObject::GetTypeInfo(void) const
// lis r3,upper; addi r3,r3,lower; blr - return global address

struct TI_80054414 { int data[4]; };
extern TI_80054414 g_80054414;

TI_80054414* fn_80054414() {
    return &g_80054414;
}
