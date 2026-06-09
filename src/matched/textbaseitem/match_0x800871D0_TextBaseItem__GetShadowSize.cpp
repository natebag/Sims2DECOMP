struct TextBaseItem {
    char pad[0x4C];
    float m_shadowSize;

    float GetShadowSize(void);
};

float TextBaseItem::GetShadowSize(void) {
    return m_shadowSize;
}
