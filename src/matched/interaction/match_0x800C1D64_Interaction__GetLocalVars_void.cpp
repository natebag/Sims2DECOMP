// 0x800C1D64 Interaction::GetLocalVars(void) (8 B)
struct Interaction { char _pad[0x24]; unsigned m_field; unsigned GetLocalVars(); };
unsigned Interaction::GetLocalVars() { return m_field; }
