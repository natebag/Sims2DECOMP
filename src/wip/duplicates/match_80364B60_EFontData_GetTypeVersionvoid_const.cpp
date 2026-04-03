// 0x80364B60 (12 bytes) - EFontData::GetTypeVersion(void) const
// lis r9,upper; lhz r3,lower(r9); blr - return unsigned short from global

struct TI_80364B60 { int data[4]; };
extern TI_80364B60 g_80364B60;

struct C_80364B60 {
    unsigned short fn() const;
};

unsigned short C_80364B60::fn() const {
    return *(unsigned short*)&g_80364B60.data[3];
}
