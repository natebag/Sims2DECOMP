// 0x802E38DC EEngine::CanReset(void) (8 B)
struct EEngine { char _pad[0xc]; unsigned m_field; unsigned CanReset(); };
unsigned EEngine::CanReset() { return m_field; }
