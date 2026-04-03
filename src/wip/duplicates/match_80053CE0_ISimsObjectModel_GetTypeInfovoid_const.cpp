// 0x80053CE0 (12 bytes) - ISimsObjectModel::GetTypeInfo(void) const
// lis r3,upper; addi r3,r3,lower; blr - return global address

struct TI_80053CE0 { int data[4]; };
extern TI_80053CE0 g_80053CE0;

TI_80053CE0* fn_80053CE0() {
    return &g_80053CE0;
}
