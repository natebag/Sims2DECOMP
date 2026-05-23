// 0x8008730C TextBaseItem::GetText(void) (8 B)
struct TextBaseItem { char _pad[0x20]; unsigned m_text; unsigned GetText(); };
unsigned TextBaseItem::GetText() { return m_text; }
