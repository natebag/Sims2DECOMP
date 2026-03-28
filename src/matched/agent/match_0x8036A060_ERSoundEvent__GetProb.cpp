struct ERSoundEvent {
    char _pad[0x1a];
    unsigned char m_prob;
    unsigned char GetProb();
};
unsigned char ERSoundEvent::GetProb() { return m_prob; }
