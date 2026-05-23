// 0x80090038 ELiveMode::InTransportMode(void) (8 B)
struct ELiveMode { char _pad[0x28]; unsigned m_inTransportMode; unsigned InTransportMode(); };
unsigned ELiveMode::InTransportMode() { return m_inTransportMode; }
