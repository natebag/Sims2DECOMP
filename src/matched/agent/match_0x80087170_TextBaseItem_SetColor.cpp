// TextBaseItem::SetColor(EVec4 &)
// Address: 0x80087170 | Size: 40 bytes
// FLAGS: -fno-elide-constructors

struct EVec4 {
    float x, y, z, w;
};

struct TextBaseItem {
    char pad[0x44];
    EVec4* m_color;
    
    void SetColor(EVec4& color);
};

void TextBaseItem::SetColor(EVec4& color) {
    register EVec4* dest = m_color;
    dest->x = color.x;
    dest->y = color.y;
    dest->z = color.z;
    dest->w = color.w;
}
