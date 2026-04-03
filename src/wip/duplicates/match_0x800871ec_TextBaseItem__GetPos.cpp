struct EVec2 {
    float x, y;
};

struct TextBaseItem {
    char pad[0x24];
    EVec2 m_pos;

    EVec2 *GetPos(void);
};

EVec2 *TextBaseItem::GetPos(void) {
    return &m_pos;
}
