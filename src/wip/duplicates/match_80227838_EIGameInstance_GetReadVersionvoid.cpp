// 0x80227838 (12 bytes) - EIGameInstance::GetReadVersion(void)
// lis r9,upper; lhz r3,lower(r9); blr - return unsigned short from global

struct TI_80227838 { int data[4]; };
extern TI_80227838 g_80227838;

struct C_80227838 {
    unsigned short fn() const;
};

unsigned short C_80227838::fn() const {
    return *(unsigned short*)&g_80227838.data[3];
}
