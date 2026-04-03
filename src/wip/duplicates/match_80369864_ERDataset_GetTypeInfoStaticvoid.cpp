// 0x80369864 (12 bytes) - ERDataset::GetTypeInfoStatic(void)
// lis r3,upper; addi r3,r3,lower; blr - return global address

struct TI_80369864 { int data[4]; };
extern TI_80369864 g_80369864;

TI_80369864* fn_80369864() {
    return &g_80369864;
}
