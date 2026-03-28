typedef unsigned short wchar_t;

struct TextBaseItem {
    char pad[0x20];
    wchar_t *m_text;

    wchar_t *GetText(void) const;
};

wchar_t *TextBaseItem::GetText(void) const {
    return m_text;
}
