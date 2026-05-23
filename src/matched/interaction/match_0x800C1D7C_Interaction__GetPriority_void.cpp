// 0x800C1D7C Interaction::GetPriority(void) (8 B)
struct Interaction { char _pad[0x28]; unsigned m_field; unsigned GetPriority(); };
unsigned Interaction::GetPriority() { return m_field; }
