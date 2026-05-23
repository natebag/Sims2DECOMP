// 0x800871D0 TextBaseItem::GetShadowSize(void) (8 B)
struct TextBaseItem { char _pad[0x4c]; float m_shadowSize; float GetShadowSize(); };
float TextBaseItem::GetShadowSize() { return m_shadowSize; }
