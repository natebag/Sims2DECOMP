// 0x80327E30 EResourceMap::GetSize(void) (8 B)
struct EResourceMap { char _pad[0x4]; unsigned m_field; unsigned GetSize(); };
unsigned EResourceMap::GetSize() { return m_field; }
