// 0x8003536C ESim::GetIsModelLoaded(void) (8 B)
struct ESim { char _pad[0x638]; unsigned m_isModelLoaded; unsigned GetIsModelLoaded(); };
unsigned ESim::GetIsModelLoaded() { return m_isModelLoaded; }
