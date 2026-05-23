// 0x80327EAC EResourceMap::GetNumEntries(void) (8 B)
struct EResourceMap { char _pad[0x4]; unsigned m_field; unsigned GetNumEntries(); };
unsigned EResourceMap::GetNumEntries() { return m_field; }
