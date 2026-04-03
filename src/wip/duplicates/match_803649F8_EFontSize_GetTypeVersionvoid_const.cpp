// 0x803649F8 (12 bytes) - EFontSize::GetTypeVersion(void) const
// lis r9,upper; lhz r3,lower(r9); blr - return unsigned short from global

struct TI_803649F8 { int data[4]; };
extern TI_803649F8 g_803649F8;

struct C_803649F8 {
    unsigned short fn() const;
};

unsigned short C_803649F8::fn() const {
    return *(unsigned short*)&g_803649F8.data[3];
}
