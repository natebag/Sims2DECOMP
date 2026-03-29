// 0x80053D10 (12 bytes) - ISimsObjectModel::GetTypeInfoStatic(void)
// lis r3,upper; addi r3,r3,lower; blr - return global address

struct TI_80053D10 { int data[4]; };
extern TI_80053D10 g_80053D10;

TI_80053D10* fn_80053D10() {
    return &g_80053D10;
}
