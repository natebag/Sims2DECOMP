// 0x800B43DC Commander::GetType(void) (8 B)
struct Commander { char _pad[0x4]; unsigned m_type; unsigned GetType(); };
unsigned Commander::GetType() { return m_type; }
