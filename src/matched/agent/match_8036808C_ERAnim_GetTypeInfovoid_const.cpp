// 0x8036808C (12 bytes) - ERAnim::GetTypeInfo(void) const
// lis r3,upper; addi r3,r3,lower; blr - return global address

struct TI_8036808C { int data[4]; };
extern TI_8036808C g_8036808C;

TI_8036808C* fn_8036808C() {
    return &g_8036808C;
}
