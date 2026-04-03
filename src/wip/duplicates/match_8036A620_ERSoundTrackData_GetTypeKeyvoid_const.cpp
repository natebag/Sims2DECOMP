// 0x8036A620 (12 bytes) - ERSoundTrackData::GetTypeKey(void) const
// lis r9,upper; lwz r3,lower(r9); blr - return word from global

struct TI_8036A620 { int data[4]; };
extern TI_8036A620 g_8036A620;

struct C_8036A620 {
    int fn() const;
};

int C_8036A620::fn() const {
    return g_8036A620.data[3];
}
