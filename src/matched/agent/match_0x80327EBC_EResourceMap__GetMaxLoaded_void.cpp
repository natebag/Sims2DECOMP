// 0x80327EBC EResourceMap::GetMaxLoaded(void) (8 B)
struct EResourceMap { char _pad[0xc]; unsigned m_field; unsigned GetMaxLoaded(); };
unsigned EResourceMap::GetMaxLoaded() { return m_field; }
