// 0x800871D0 (8 bytes)
class TextBaseItem {
public:
    char pad[76];
    float m_shadowSize;

    float GetShadowSize(void);
};

float TextBaseItem::GetShadowSize(void) {
    return m_shadowSize;
}
