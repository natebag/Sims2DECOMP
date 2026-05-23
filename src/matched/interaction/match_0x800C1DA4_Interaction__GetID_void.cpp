// 0x800C1DA4 Interaction::GetID(void) (8 B)
struct Interaction { char _pad[0x38]; unsigned m_field; unsigned GetID(); };
unsigned Interaction::GetID() { return m_field; }
