// 0x802277FC (12 bytes) - EIGameInstance::GetTypeInfo(void) const
// lis r3,upper; addi r3,r3,lower; blr - return global address

struct TI_802277FC { int data[4]; };
extern TI_802277FC g_802277FC;

TI_802277FC* fn_802277FC() {
    return &g_802277FC;
}
