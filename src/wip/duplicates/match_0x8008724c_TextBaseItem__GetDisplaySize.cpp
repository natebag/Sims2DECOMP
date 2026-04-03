struct EVec2 {
    float x, y;
};

struct TextBaseItem {
    char pad[0x2C];
    EVec2 m_displaySize;

    EVec2 *GetDisplaySize(void);
};

EVec2 *TextBaseItem::GetDisplaySize(void) {
    return &m_displaySize;
}
