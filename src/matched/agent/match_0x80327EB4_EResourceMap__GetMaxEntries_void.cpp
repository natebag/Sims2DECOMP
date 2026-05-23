// 0x80327EB4 EResourceMap::GetMaxEntries(void) (8 B)
struct EResourceMap { char _pad[0x8]; unsigned m_field; unsigned GetMaxEntries(); };
unsigned EResourceMap::GetMaxEntries() { return m_field; }
