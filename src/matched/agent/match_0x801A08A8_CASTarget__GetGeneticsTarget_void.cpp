// 0x801A08A8 CASTarget::GetGeneticsTarget(void) (8 B)
struct CASTarget { char _pad[0x1370]; unsigned m_field; unsigned GetGeneticsTarget(); };
unsigned CASTarget::GetGeneticsTarget() { return m_field; }
