// 0x802E38CC EEngine::GetCurrentLevel(void) (8 B)
struct EEngine { char _pad[0x30]; unsigned m_field; unsigned GetCurrentLevel(); };
unsigned EEngine::GetCurrentLevel() { return m_field; }
