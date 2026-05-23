// 0x800C1C84 Interaction::GetIconObject(void) (8 B)
struct Interaction { char _pad[0x10]; unsigned m_field; unsigned GetIconObject(); };
unsigned Interaction::GetIconObject() { return m_field; }
