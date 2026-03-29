// 0x803648A8 (12 bytes) - EFontPage::GetReadVersion(void)
// lis r9,upper; lhz r3,lower(r9); blr - return unsigned short from global

struct TI_803648A8 { int data[4]; };
extern TI_803648A8 g_803648A8;

struct C_803648A8 {
    unsigned short fn() const;
};

unsigned short C_803648A8::fn() const {
    return *(unsigned short*)&g_803648A8.data[3];
}
