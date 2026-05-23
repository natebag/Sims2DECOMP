// 0x800873A4 TextBaseItem::GetStyle(void) (8 B)
struct TextBaseItem { char _pad[0x6c]; unsigned m_style; unsigned GetStyle(); };
unsigned TextBaseItem::GetStyle() { return m_style; }
