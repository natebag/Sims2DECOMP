struct ERSoundEvent {
    char _pad[0x18];
    short m_volume;
    void SetVolume(int val);
};
void ERSoundEvent::SetVolume(int val) { m_volume = val; }
