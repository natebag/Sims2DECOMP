// 0x80364A10 (12 bytes) - EFontSize::GetReadVersion(void)
// lis r9,upper; lhz r3,lower(r9); blr - return unsigned short from global

struct TI_80364A10 { int data[4]; };
extern TI_80364A10 g_80364A10;

struct C_80364A10 {
    unsigned short fn() const;
};

unsigned short C_80364A10::fn() const {
    return *(unsigned short*)&g_80364A10.data[3];
}
