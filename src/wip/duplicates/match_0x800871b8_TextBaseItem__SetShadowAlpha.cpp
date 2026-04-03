struct TextBaseItem {
    char pad[0x48];
    float m_shadowAlpha;

    void SetShadowAlpha(float alpha);
};

void TextBaseItem::SetShadowAlpha(float alpha) {
    m_shadowAlpha = alpha;
}
