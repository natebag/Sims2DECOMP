// 0x80364B78 (12 bytes) - EFontData::GetReadVersion(void)
// lis r9,upper; lhz r3,lower(r9); blr - return unsigned short from global

struct TI_80364B78 { int data[4]; };
extern TI_80364B78 g_80364B78;

struct C_80364B78 {
    unsigned short fn() const;
};

unsigned short C_80364B78::fn() const {
    return *(unsigned short*)&g_80364B78.data[3];
}
