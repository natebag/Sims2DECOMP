// 0x800C1D84 Interaction::SetPriority(int) (8 B)
struct Interaction { char _pad[0x28]; unsigned m_field; void SetPriority(unsigned); };
void Interaction::SetPriority(unsigned val) { m_field = val; }
