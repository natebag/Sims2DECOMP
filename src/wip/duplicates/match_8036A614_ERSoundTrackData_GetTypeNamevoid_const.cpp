// 0x8036A614 (12 bytes) - ERSoundTrackData::GetTypeName(void) const
// lis r9,upper; lwz r3,lower(r9); blr - return word from global

struct TI_8036A614 { int data[4]; };
extern TI_8036A614 g_8036A614;

struct C_8036A614 {
    int fn() const;
};

int C_8036A614::fn() const {
    return g_8036A614.data[3];
}
