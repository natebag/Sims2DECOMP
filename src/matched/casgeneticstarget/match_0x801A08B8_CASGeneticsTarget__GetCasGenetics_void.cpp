// 0x801A08B8 CASGeneticsTarget::GetCasGenetics(void) (8 B)
struct CASGeneticsTarget { char _pad[0x94]; unsigned m_field; unsigned GetCasGenetics(); };
unsigned CASGeneticsTarget::GetCasGenetics() { return m_field; }
