// 0x8008720C TextBaseItem::GetPosY(void) (8 B)
struct TextBaseItem { char _pad[0x28]; float m_posY; float GetPosY(); };
float TextBaseItem::GetPosY() { return m_posY; }
