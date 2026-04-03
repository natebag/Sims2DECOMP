struct EVec4 {
    float x, y, z;
    float w;
};

struct TextBaseItem {
    char pad[0x44];
    EVec4 *m_color;

    float GetAlpha(void);
};

float TextBaseItem::GetAlpha(void) {
    return m_color->w;
}
