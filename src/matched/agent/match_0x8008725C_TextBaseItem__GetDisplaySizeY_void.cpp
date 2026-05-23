// 0x8008725C TextBaseItem::GetDisplaySizeY(void) (8 B)
struct TextBaseItem { char _pad[0x30]; float m_displaySizeY; float GetDisplaySizeY(); };
float TextBaseItem::GetDisplaySizeY() { return m_displaySizeY; }
