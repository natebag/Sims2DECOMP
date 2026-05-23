// 0x800871EC TextBaseItem::GetPos(void) (8 B)
struct TextBaseItem { char _pad[0x24]; float m_pos[2]; float* GetPos(); };
float* TextBaseItem::GetPos() { return m_pos; }
