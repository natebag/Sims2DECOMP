struct EVec4;

struct TextBaseItem {
    char pad[0x44];
    EVec4 *m_color;

    EVec4 *GetColor(void);
};

EVec4 *TextBaseItem::GetColor(void) {
    return m_color;
}
