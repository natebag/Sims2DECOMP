// 0x8036AC54 (12 bytes) - REffectsEmitter::GetTypeVersion(void) const
// lis r9,upper; lhz r3,lower(r9); blr - return unsigned short from global

struct TI_8036AC54 { int data[4]; };
extern TI_8036AC54 g_8036AC54;

struct C_8036AC54 {
    unsigned short fn() const;
};

unsigned short C_8036AC54::fn() const {
    return *(unsigned short*)&g_8036AC54.data[3];
}
