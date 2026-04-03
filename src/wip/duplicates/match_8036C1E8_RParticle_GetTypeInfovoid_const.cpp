// 0x8036C1E8 (12 bytes) - RParticle::GetTypeInfo(void) const
// lis r3,upper; addi r3,r3,lower; blr - return global address

struct TI_8036C1E8 { int data[4]; };
extern TI_8036C1E8 g_8036C1E8;

TI_8036C1E8* fn_8036C1E8() {
    return &g_8036C1E8;
}
