struct ERSoundEvent {
    char _pad[0x18];
    unsigned short m_volume;
    unsigned short GetVolume();
};
unsigned short ERSoundEvent::GetVolume() { return m_volume; }
