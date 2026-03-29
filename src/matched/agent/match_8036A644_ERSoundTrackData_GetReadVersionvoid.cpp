// 0x8036A644 (12 bytes) - ERSoundTrackData::GetReadVersion(void)
// lis r9,upper; lhz r3,lower(r9); blr - return unsigned short from global

struct TI_8036A644 { int data[4]; };
extern TI_8036A644 g_8036A644;

struct C_8036A644 {
    unsigned short fn() const;
};

unsigned short C_8036A644::fn() const {
    return *(unsigned short*)&g_8036A644.data[3];
}
