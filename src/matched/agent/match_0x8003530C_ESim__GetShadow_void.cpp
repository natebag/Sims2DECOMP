// 0x8003530C ESim::GetShadow(void) (8 B)
struct ESim { char _pad[0x3e0]; unsigned m_shadow; unsigned GetShadow(); };
unsigned ESim::GetShadow() { return m_shadow; }
