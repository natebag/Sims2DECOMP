// 0x8036B184 (12 bytes) - REffectsSequencer::GetTypeVersion(void) const
// lis r9,upper; lhz r3,lower(r9); blr - return unsigned short from global

struct TI_8036B184 { int data[4]; };
extern TI_8036B184 g_8036B184;

struct C_8036B184 {
    unsigned short fn() const;
};

unsigned short C_8036B184::fn() const {
    return *(unsigned short*)&g_8036B184.data[3];
}
