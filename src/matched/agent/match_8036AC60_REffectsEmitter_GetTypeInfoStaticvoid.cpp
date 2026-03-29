// 0x8036AC60 (12 bytes) - REffectsEmitter::GetTypeInfoStatic(void)
// lis r3,upper; addi r3,r3,lower; blr - return global address

struct TI_8036AC60 { int data[4]; };
extern TI_8036AC60 g_8036AC60;

TI_8036AC60* fn_8036AC60() {
    return &g_8036AC60;
}
