// 0x800871FC TextBaseItem::GetPosX(void) (8 B)
struct TextBaseItem { char _pad[0x24]; float m_posX; float GetPosX(); };
float TextBaseItem::GetPosX() { return m_posX; }
