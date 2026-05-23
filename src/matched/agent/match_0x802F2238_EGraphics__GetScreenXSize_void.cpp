// 0x802F2238 EGraphics::GetScreenXSize(void) (8 B)
struct EGraphics { char _pad[0x18]; unsigned m_field; unsigned GetScreenXSize(); };
unsigned EGraphics::GetScreenXSize() { return m_field; }
