// 0x8036C218 (12 bytes) - RParticle::GetTypeInfoStatic(void)
// lis r3,upper; addi r3,r3,lower; blr - return global address

struct TI_8036C218 { int data[4]; };
extern TI_8036C218 g_8036C218;

TI_8036C218* fn_8036C218() {
    return &g_8036C218;
}
