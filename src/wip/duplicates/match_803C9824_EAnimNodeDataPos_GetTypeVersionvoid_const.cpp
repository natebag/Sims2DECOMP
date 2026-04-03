// 0x803C9824 (12 bytes) - EAnimNodeDataPos::GetTypeVersion(void) const
// lis r9,upper; lhz r3,lower(r9); blr - return unsigned short from global

struct TI_803C9824 { int data[4]; };
extern TI_803C9824 g_803C9824;

struct C_803C9824 {
    unsigned short fn() const;
};

unsigned short C_803C9824::fn() const {
    return *(unsigned short*)&g_803C9824.data[3];
}
