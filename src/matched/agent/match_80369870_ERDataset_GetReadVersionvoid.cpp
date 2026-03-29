// 0x80369870 (12 bytes) - ERDataset::GetReadVersion(void)
// lis r9,upper; lhz r3,lower(r9); blr - return unsigned short from global

struct TI_80369870 { int data[4]; };
extern TI_80369870 g_80369870;

struct C_80369870 {
    unsigned short fn() const;
};

unsigned short C_80369870::fn() const {
    return *(unsigned short*)&g_80369870.data[3];
}
