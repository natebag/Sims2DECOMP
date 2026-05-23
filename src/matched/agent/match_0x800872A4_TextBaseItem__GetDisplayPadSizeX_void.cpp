// 0x800872A4 TextBaseItem::GetDisplayPadSizeX(void) (8 B)
struct TextBaseItem { char _pad[0x34]; float m_displayPadSizeX; float GetDisplayPadSizeX(); };
float TextBaseItem::GetDisplayPadSizeX() { return m_displayPadSizeX; }
