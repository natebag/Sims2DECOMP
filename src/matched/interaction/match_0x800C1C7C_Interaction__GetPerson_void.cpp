// 0x800C1C7C Interaction::GetPerson(void) (8 B)
struct Interaction { char _pad[0x8]; unsigned m_field; unsigned GetPerson(); };
unsigned Interaction::GetPerson() { return m_field; }
