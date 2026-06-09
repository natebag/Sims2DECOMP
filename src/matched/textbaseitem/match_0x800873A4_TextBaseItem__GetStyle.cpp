struct TextBaseItem {
    char pad[0x6C];
    int m_style;

    int GetStyle(void) const;
};

int TextBaseItem::GetStyle(void) const {
    return m_style;
}
