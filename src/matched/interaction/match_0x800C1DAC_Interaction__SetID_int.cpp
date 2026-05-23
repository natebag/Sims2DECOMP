// 0x800C1DAC Interaction::SetID(int) (8 B)
struct Interaction { char _pad[0x38]; unsigned m_field; void SetID(unsigned); };
void Interaction::SetID(unsigned val) { m_field = val; }
