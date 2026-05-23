// 0x80087354 TextBaseItem::GetFont(void) (8 B)
struct TextBaseItem { char _pad[0x50]; unsigned m_font; unsigned GetFont(); };
unsigned TextBaseItem::GetFont() { return m_font; }
