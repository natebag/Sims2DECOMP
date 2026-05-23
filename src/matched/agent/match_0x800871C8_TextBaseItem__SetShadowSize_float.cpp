// 0x800871C8 TextBaseItem::SetShadowSize(float) (8 B)
struct TextBaseItem { char _pad[0x4c]; float m_shadowSize; void SetShadowSize(float); };
void TextBaseItem::SetShadowSize(float val) { m_shadowSize = val; }
