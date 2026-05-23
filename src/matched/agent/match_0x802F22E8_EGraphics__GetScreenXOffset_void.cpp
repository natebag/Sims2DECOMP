// 0x802F22E8 EGraphics::GetScreenXOffset(void) (8 B)
struct EGraphics { char _pad[0x20]; unsigned m_field; unsigned GetScreenXOffset(); };
unsigned EGraphics::GetScreenXOffset() { return m_field; }
