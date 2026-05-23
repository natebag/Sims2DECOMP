// 0x802F22C8 EGraphics::GetActualScreenXSize(void) (8 B)
struct EGraphics { char _pad[0x18]; unsigned m_field; unsigned GetActualScreenXSize(); };
unsigned EGraphics::GetActualScreenXSize() { return m_field; }
