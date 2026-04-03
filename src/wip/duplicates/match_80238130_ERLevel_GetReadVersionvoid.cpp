// 0x80238130 (12 bytes) - ERLevel::GetReadVersion(void)
// lis r9,upper; lhz r3,lower(r9); blr - return unsigned short from global

struct TI_80238130 { int data[4]; };
extern TI_80238130 g_80238130;

struct C_80238130 {
    unsigned short fn() const;
};

unsigned short C_80238130::fn() const {
    return *(unsigned short*)&g_80238130.data[3];
}
