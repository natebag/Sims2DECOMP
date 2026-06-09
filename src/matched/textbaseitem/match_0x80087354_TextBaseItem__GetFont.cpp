struct ERFont;

struct TextBaseItem {
    char pad[0x50];
    ERFont *m_font;

    ERFont *GetFont(void) const;
};

ERFont *TextBaseItem::GetFont(void) const {
    return m_font;
}
