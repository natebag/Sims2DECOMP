// 0x80087204 TextBaseItem::SetPosY(float) (8 B)
struct TextBaseItem { char _pad[0x28]; float m_posY; void SetPosY(float); };
void TextBaseItem::SetPosY(float val) { m_posY = val; }
