// 0x80090090 ELiveMode::SetInitialized(bool) (8 B)
struct ELiveMode { char _pad[0x30]; unsigned m_initialized; void SetInitialized(bool); };
void ELiveMode::SetInitialized(bool val) { m_initialized = val; }
