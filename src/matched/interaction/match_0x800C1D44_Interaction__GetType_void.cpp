// 0x800C1D44 Interaction::GetType(void) (8 B)
struct Interaction { char _pad[0x4]; unsigned m_field; unsigned GetType(); };
unsigned Interaction::GetType() { return m_field; }
