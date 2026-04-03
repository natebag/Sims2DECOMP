// 0x80369834 (12 bytes) - ERDataset::GetTypeInfo(void) const
// lis r3,upper; addi r3,r3,lower; blr - return global address

struct TI_80369834 { int data[4]; };
extern TI_80369834 g_80369834;

TI_80369834* fn_80369834() {
    return &g_80369834;
}
