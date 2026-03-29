// 0x8036AC30 (12 bytes) - REffectsEmitter::GetTypeInfo(void) const
// lis r3,upper; addi r3,r3,lower; blr - return global address

struct TI_8036AC30 { int data[4]; };
extern TI_8036AC30 g_8036AC30;

TI_8036AC30* fn_8036AC30() {
    return &g_8036AC30;
}
