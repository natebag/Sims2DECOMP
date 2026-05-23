// 0x800871B8 TextBaseItem::SetShadowAlpha(float) (8 B)
struct TextBaseItem { char _pad[0x48]; float m_shadowAlpha; void SetShadowAlpha(float); };
void TextBaseItem::SetShadowAlpha(float val) { m_shadowAlpha = val; }
