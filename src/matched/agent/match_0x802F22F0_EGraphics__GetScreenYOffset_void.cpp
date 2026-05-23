// 0x802F22F0 EGraphics::GetScreenYOffset(void) (8 B)
struct EGraphics { char _pad[0x24]; unsigned m_field; unsigned GetScreenYOffset(); };
unsigned EGraphics::GetScreenYOffset() { return m_field; }
