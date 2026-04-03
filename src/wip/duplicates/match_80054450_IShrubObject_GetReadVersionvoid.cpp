// 0x80054450 (12 bytes) - IShrubObject::GetReadVersion(void)
// lis r9,upper; lhz r3,lower(r9); blr - return unsigned short from global

struct TI_80054450 { int data[4]; };
extern TI_80054450 g_80054450;

struct C_80054450 {
    unsigned short fn() const;
};

unsigned short C_80054450::fn() const {
    return *(unsigned short*)&g_80054450.data[3];
}
