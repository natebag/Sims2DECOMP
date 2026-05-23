// 0x800C1FF8 Interaction::SetFlags(int) (8 B)
struct Interaction { char _pad[0x3c]; unsigned m_field; void SetFlags(unsigned); };
void Interaction::SetFlags(unsigned val) { m_field = val; }
