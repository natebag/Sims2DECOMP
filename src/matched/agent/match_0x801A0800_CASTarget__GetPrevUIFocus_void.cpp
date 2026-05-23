// 0x801A0800 CASTarget::GetPrevUIFocus(void) (8 B)
struct CASTarget { char _pad[0xa0]; unsigned m_field; unsigned GetPrevUIFocus(); };
unsigned CASTarget::GetPrevUIFocus() { return m_field; }
