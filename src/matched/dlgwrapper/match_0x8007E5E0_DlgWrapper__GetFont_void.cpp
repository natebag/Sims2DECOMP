// 0x8007E5E0 DlgWrapper::GetFont(void) (8 B)
struct DlgWrapper { char _pad[0xa8]; unsigned m_font; unsigned GetFont(); };
unsigned DlgWrapper::GetFont() { return m_font; }
