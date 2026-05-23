// 0x80162028 CasMediator::GetNumListeners(void) (8 B)
struct CasMediator { char _pad[0x8]; unsigned m_field; unsigned GetNumListeners(); };
unsigned CasMediator::GetNumListeners() { return m_field; }
