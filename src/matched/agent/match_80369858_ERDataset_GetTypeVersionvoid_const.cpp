// 0x80369858 (12 bytes) - ERDataset::GetTypeVersion(void) const
// lis r9,upper; lhz r3,lower(r9); blr - return unsigned short from global

struct TI_80369858 { int data[4]; };
extern TI_80369858 g_80369858;

struct C_80369858 {
    unsigned short fn() const;
};

unsigned short C_80369858::fn() const {
    return *(unsigned short*)&g_80369858.data[3];
}
