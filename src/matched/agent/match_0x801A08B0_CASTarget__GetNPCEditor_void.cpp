// 0x801A08B0 CASTarget::GetNPCEditor(void) (8 B)
struct CASTarget { char _pad[0x1354]; unsigned m_field; unsigned GetNPCEditor(); };
unsigned CASTarget::GetNPCEditor() { return m_field; }
