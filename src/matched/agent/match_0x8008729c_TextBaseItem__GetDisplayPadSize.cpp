struct EVec2 {
    float x, y;
};

struct TextBaseItem {
    char pad[0x34];
    EVec2 m_displayPadSize;

    EVec2 *GetDisplayPadSize(void);
};

EVec2 *TextBaseItem::GetDisplayPadSize(void) {
    return &m_displayPadSize;
}
