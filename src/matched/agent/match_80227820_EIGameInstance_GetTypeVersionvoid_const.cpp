// 0x80227820 (12 bytes) - EIGameInstance::GetTypeVersion(void) const
// lis r9,upper; lhz r3,lower(r9); blr - return unsigned short from global

struct TI_80227820 { int data[4]; };
extern TI_80227820 g_80227820;

struct C_80227820 {
    unsigned short fn() const;
};

unsigned short C_80227820::fn() const {
    return *(unsigned short*)&g_80227820.data[3];
}
