// 0x80087198 TextBaseItem::GetColor(void) (8 B)
struct TextBaseItem { char _pad[0x44]; unsigned m_color; unsigned GetColor(); };
unsigned TextBaseItem::GetColor() { return m_color; }
