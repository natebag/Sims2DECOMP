// 0x800871C0 (8 bytes)
class TextBaseItem {
public:
    char pad[72];
    float m_shadowAlpha;

    float GetShadowAlpha(void);
};

float TextBaseItem::GetShadowAlpha(void) {
    return m_shadowAlpha;
}
