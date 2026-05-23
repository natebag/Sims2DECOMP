// 0x80090098 ELiveMode::IsInitialized(void) (8 B)
struct ELiveMode { char _pad[0x30]; unsigned m_initialized; unsigned IsInitialized(); };
unsigned ELiveMode::IsInitialized() { return m_initialized; }
