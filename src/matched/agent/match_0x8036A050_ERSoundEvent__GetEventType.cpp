struct ERSoundEvent {
    char _pad[0x14];
    unsigned char m_eventType;
    unsigned char GetEventType();
};
unsigned char ERSoundEvent::GetEventType() { return m_eventType; }
