// 0x8036A62C (12 bytes) - ERSoundTrackData::GetTypeVersion(void) const
// lis r9,upper; lhz r3,lower(r9); blr - return unsigned short from global

struct TI_8036A62C { int data[4]; };
extern TI_8036A62C g_8036A62C;

struct C_8036A62C {
    unsigned short fn() const;
};

unsigned short C_8036A62C::fn() const {
    return *(unsigned short*)&g_8036A62C.data[3];
}
