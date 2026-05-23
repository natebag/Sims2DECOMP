// 0x8031C62C ERQuickdata::GetImage(void) (8 B)
struct ERQuickdata { char _pad[0x14]; unsigned m_field; unsigned GetImage(); };
unsigned ERQuickdata::GetImage() { return m_field; }
