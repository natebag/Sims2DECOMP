// 0x801A0808 CASTarget::GetCurPartUIFocus(void) (8 B)
struct CASTarget { char _pad[0xa4]; unsigned m_field; unsigned GetCurPartUIFocus(); };
unsigned CASTarget::GetCurPartUIFocus() { return m_field; }
