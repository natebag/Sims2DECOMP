struct TextBaseItem {
    char pad[0x4C];
    float m_shadowSize;

    void SetShadowSize(float size);
};

void TextBaseItem::SetShadowSize(float size) {
    m_shadowSize = size;
}
