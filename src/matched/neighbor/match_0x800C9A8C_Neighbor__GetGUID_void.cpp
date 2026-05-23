// 0x800C9A8C Neighbor::GetGUID(void) (8 B)
struct Neighbor { char _pad[0x8]; unsigned m_field; unsigned GetGUID(); };
unsigned Neighbor::GetGUID() { return m_field; }
