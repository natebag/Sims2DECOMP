struct TextBaseItem {
    char pad[0x54];
    float m_fontSize;

    float GetFontSize(void) const;
};

float TextBaseItem::GetFontSize(void) const {
    return m_fontSize;
}
