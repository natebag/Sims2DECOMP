// 0x8036B160 (12 bytes) - REffectsSequencer::GetTypeInfo(void) const
// lis r3,upper; addi r3,r3,lower; blr - return global address

struct TI_8036B160 { int data[4]; };
extern TI_8036B160 g_8036B160;

TI_8036B160* fn_8036B160() {
    return &g_8036B160;
}
