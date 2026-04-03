// 0x80048434 (12 bytes) - EIFloor::GetReadVersion(void)
// lis r9,upper; lhz r3,lower(r9); blr - return unsigned short from global

struct TI_80048434 { int data[4]; };
extern TI_80048434 g_80048434;

struct C_80048434 {
    unsigned short fn() const;
};

unsigned short C_80048434::fn() const {
    return *(unsigned short*)&g_80048434.data[3];
}
