struct EVec4 {
    float x, y, z;
    float w;
};

struct TextBaseItem {
    char pad[0x44];
    EVec4 *m_color;

    void SetAlpha(float alpha);
};

void TextBaseItem::SetAlpha(float alpha) {
    m_color->w = alpha;
}
