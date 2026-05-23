// 0x802F22D0 EGraphics::GetActualScreenYSize(void) (8 B)
struct EGraphics { char _pad[0x1c]; unsigned m_field; unsigned GetActualScreenYSize(); };
unsigned EGraphics::GetActualScreenYSize() { return m_field; }
