// 0x800C1D6C Interaction::GetLocalVarsCount(void) (8 B)
struct Interaction { char _pad[0x20]; unsigned m_field; unsigned GetLocalVarsCount(); };
unsigned Interaction::GetLocalVarsCount() { return m_field; }
