// 0x80368C80 (12 bytes) - ERCharacter::GetReadVersion(void)
// lis r9,upper; lhz r3,lower(r9); blr - return unsigned short from global

struct TI_80368C80 { int data[4]; };
extern TI_80368C80 g_80368C80;

struct C_80368C80 {
    unsigned short fn() const;
};

unsigned short C_80368C80::fn() const {
    return *(unsigned short*)&g_80368C80.data[3];
}
