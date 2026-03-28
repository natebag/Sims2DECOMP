// 0x8036A058 (8 bytes) - ERSoundEvent::GetVolume(void)
// lhz r3, 24(r3); blr

class ERSoundEvent {
public:
    int pad0; int pad1; int pad2; int pad3; int pad4;
    unsigned short pad5; // 0x14
    unsigned short pad6; // 0x16
    unsigned short m_volume; // 0x18

    unsigned short GetVolume();
};

unsigned short ERSoundEvent::GetVolume() { return m_volume; }
