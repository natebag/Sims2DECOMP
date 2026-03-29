// 0x80367260 (12 bytes) - ERAmbientScore::GetReadVersion(void)
// lis r9,upper; lhz r3,lower(r9); blr - return unsigned short from global

struct TI_80367260 { int data[4]; };
extern TI_80367260 g_80367260;

struct C_80367260 {
    unsigned short fn() const;
};

unsigned short C_80367260::fn() const {
    return *(unsigned short*)&g_80367260.data[3];
}
