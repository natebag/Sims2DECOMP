// 0x8031C634 ERQuickdata::GetImageSize(void) (8 B)
struct ERQuickdata { char _pad[0x18]; unsigned m_field; unsigned GetImageSize(); };
unsigned ERQuickdata::GetImageSize() { return m_field; }
