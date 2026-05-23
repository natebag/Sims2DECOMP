// 0x802BBAD8 AptBoolean::GetBool(void) (8 B)
struct AptBoolean { char _pad[0xc]; unsigned m_field; unsigned GetBool(); };
unsigned AptBoolean::GetBool() { return m_field; }
