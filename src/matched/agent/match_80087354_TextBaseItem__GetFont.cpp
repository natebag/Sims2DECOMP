// 0x80087354 (8 bytes)
typedef void ERFont;

class TextBaseItem {
public:
    char pad[80];
    ERFont *m_font;

    ERFont *GetFont(void) const;
};

ERFont *TextBaseItem::GetFont(void) const {
    return m_font;
}
