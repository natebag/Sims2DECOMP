// 0x801A0810 CASTarget::GetCurrentSimNumber(void) (8 B)
struct CASTarget { char _pad[0x134c]; unsigned m_field; unsigned GetCurrentSimNumber(); };
unsigned CASTarget::GetCurrentSimNumber() { return m_field; }
