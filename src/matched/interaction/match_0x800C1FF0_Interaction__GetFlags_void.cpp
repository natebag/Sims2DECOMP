// 0x800C1FF0 Interaction::GetFlags(void) (8 B)
struct Interaction { char _pad[0x3c]; unsigned m_field; unsigned GetFlags(); };
unsigned Interaction::GetFlags() { return m_field; }
