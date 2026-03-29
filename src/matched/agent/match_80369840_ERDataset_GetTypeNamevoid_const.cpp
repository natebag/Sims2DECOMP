// 0x80369840 (12 bytes) - ERDataset::GetTypeName(void) const
// lis r9,upper; lwz r3,lower(r9); blr - return word from global

struct TI_80369840 { int data[4]; };
extern TI_80369840 g_80369840;

struct C_80369840 {
    int fn() const;
};

int C_80369840::fn() const {
    return g_80369840.data[3];
}
