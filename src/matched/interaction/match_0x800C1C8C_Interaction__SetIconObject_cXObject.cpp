// 0x800C1C8C Interaction::SetIconObject(cXObject) (8 B)
struct Interaction { char _pad[0x10]; unsigned m_field; void SetIconObject(unsigned); };
void Interaction::SetIconObject(unsigned val) { m_field = val; }
