// 0x80054444 (12 bytes) - IShrubObject::GetTypeInfoStatic(void)
// lis r3,upper; addi r3,r3,lower; blr - return global address

struct TI_80054444 { int data[4]; };
extern TI_80054444 g_80054444;

TI_80054444* fn_80054444() {
    return &g_80054444;
}
