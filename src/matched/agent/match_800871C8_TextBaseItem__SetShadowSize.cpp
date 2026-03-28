// 0x800871C8 (8 bytes)
class TextBaseItem {
public:
    char pad[76];
    float m_shadowSize;

    void SetShadowSize(float size);
};

void TextBaseItem::SetShadowSize(float size) {
    m_shadowSize = size;
}
