// 0x802AED0C AptString::GetNext(void) (8 B)
struct AptString { char _pad[0x10]; unsigned m_field; unsigned GetNext(); };
unsigned AptString::GetNext() { return m_field; }
