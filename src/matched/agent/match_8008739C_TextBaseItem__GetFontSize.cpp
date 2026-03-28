// 0x8008739C (8 bytes)
class TextBaseItem {
public:
    char pad[84];
    float m_fontSize;

    float GetFontSize(void) const;
};

float TextBaseItem::GetFontSize(void) const {
    return m_fontSize;
}
