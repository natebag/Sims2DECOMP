// 0x800C9A94 Neighbor::SetGUID(int) (8 B)
struct Neighbor { char _pad[0x8]; unsigned m_field; void SetGUID(unsigned); };
void Neighbor::SetGUID(unsigned val) { m_field = val; }
