// 0x8008739C TextBaseItem::GetFontSize(void) (8 B)
struct TextBaseItem { char _pad[0x54]; float m_fontSize; float GetFontSize(); };
float TextBaseItem::GetFontSize() { return m_fontSize; }
