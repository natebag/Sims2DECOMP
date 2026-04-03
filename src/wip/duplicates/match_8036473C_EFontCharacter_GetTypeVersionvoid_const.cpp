// 0x8036473C (12 bytes) - EFontCharacter::GetTypeVersion(void) const
// lis r9,upper; lhz r3,lower(r9); blr - return unsigned short from global

struct TI_8036473C { int data[4]; };
extern TI_8036473C g_8036473C;

struct C_8036473C {
    unsigned short fn() const;
};

unsigned short C_8036473C::fn() const {
    return *(unsigned short*)&g_8036473C.data[3];
}
