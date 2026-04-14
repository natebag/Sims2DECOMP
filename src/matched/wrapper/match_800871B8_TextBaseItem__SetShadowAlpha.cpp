// 0x800871B8 (8 bytes)
class TextBaseItem {
public:
    char pad[72];
    float m_shadowAlpha;

    void SetShadowAlpha(float alpha);
};

void TextBaseItem::SetShadowAlpha(float alpha) {
    m_shadowAlpha = alpha;
}
