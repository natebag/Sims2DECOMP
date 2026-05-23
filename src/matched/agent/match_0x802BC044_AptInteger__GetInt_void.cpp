// 0x802BC044 AptInteger::GetInt(void) (8 B)
struct AptInteger { char _pad[0xc]; unsigned m_field; unsigned GetInt(); };
unsigned AptInteger::GetInt() { return m_field; }
