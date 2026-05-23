// 0x80087254 TextBaseItem::GetDisplaySizeX(void) (8 B)
struct TextBaseItem { char _pad[0x2c]; float m_displaySizeX; float GetDisplaySizeX(); };
float TextBaseItem::GetDisplaySizeX() { return m_displaySizeX; }
