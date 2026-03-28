struct TextBaseItem {
    char pad[0x48];
    float m_shadowAlpha;

    float GetShadowAlpha(void);
};

float TextBaseItem::GetShadowAlpha(void) {
    return m_shadowAlpha;
}
