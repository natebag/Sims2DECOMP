// 0x800871F4 TextBaseItem::SetPosX(float) (8 B)
struct TextBaseItem { char _pad[0x24]; float m_posX; void SetPosX(float); };
void TextBaseItem::SetPosX(float val) { m_posX = val; }
