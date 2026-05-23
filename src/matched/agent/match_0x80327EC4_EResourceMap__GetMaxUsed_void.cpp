// 0x80327EC4 EResourceMap::GetMaxUsed(void) (8 B)
struct EResourceMap { char _pad[0x10]; unsigned m_field; unsigned GetMaxUsed(); };
unsigned EResourceMap::GetMaxUsed() { return m_field; }
