// 0x80083964 MUWrapper::GetFont(void) (8 B)
struct MUWrapper { char _pad[0xa4]; unsigned m_font; unsigned GetFont(); };
unsigned MUWrapper::GetFont() { return m_font; }
