// 0x800878AC IconItem::GetAlpha(void) (8 B)
struct IconItem { char _pad[0x2c]; float m_alpha; float GetAlpha(); };
float IconItem::GetAlpha() { return m_alpha; }
