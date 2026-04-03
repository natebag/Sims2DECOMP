// 0x80364890 (12 bytes) - EFontPage::GetTypeVersion(void) const
// lis r9,upper; lhz r3,lower(r9); blr - return unsigned short from global

struct TI_80364890 { int data[4]; };
extern TI_80364890 g_80364890;

struct C_80364890 {
    unsigned short fn() const;
};

unsigned short C_80364890::fn() const {
    return *(unsigned short*)&g_80364890.data[3];
}
