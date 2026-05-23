// 0x800871C0 TextBaseItem::GetShadowAlpha(void) (8 B)
struct TextBaseItem { char _pad[0x48]; float m_shadowAlpha; float GetShadowAlpha(); };
float TextBaseItem::GetShadowAlpha() { return m_shadowAlpha; }
