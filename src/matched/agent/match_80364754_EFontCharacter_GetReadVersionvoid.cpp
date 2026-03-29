// 0x80364754 (12 bytes) - EFontCharacter::GetReadVersion(void)
// lis r9,upper; lhz r3,lower(r9); blr - return unsigned short from global

struct TI_80364754 { int data[4]; };
extern TI_80364754 g_80364754;

struct C_80364754 {
    unsigned short fn() const;
};

unsigned short C_80364754::fn() const {
    return *(unsigned short*)&g_80364754.data[3];
}
