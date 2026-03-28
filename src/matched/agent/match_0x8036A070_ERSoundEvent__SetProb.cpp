struct ERSoundEvent {
    char _pad[0x1a];
    unsigned char m_prob;
    void SetProb(int val);
};
void ERSoundEvent::SetProb(int val) { m_prob = val; }
