// 0x802F2240 EGraphics::GetScreenYSize(void) (8 B)
struct EGraphics { char _pad[0x1c]; unsigned m_field; unsigned GetScreenYSize(); };
unsigned EGraphics::GetScreenYSize() { return m_field; }
