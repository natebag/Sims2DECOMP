// 0x802A9880 AptAnimationPoolData::GetActionPool(void) (8 B)
struct AptAnimationPoolData { char _pad[0x98]; unsigned m_field; unsigned GetActionPool(); };
unsigned AptAnimationPoolData::GetActionPool() { return m_field; }
