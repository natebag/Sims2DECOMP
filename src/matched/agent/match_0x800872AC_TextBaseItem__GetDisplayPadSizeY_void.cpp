// 0x800872AC TextBaseItem::GetDisplayPadSizeY(void) (8 B)
struct TextBaseItem { char _pad[0x38]; float m_displayPadSizeY; float GetDisplayPadSizeY(); };
float TextBaseItem::GetDisplayPadSizeY() { return m_displayPadSizeY; }
