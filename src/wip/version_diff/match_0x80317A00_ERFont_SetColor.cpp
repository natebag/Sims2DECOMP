// ERFont::SetColor(EVec4 &)
// Address: 0x80317A00 | Size: 40 bytes
// FLAGS: -fno-elide-constructors

struct EVec4 {
    float x, y, z, w;
};

struct ERFont {
    char pad[0x58];
    EVec4 m_color;
    
    void SetColor(EVec4& color);
};

void ERFont::SetColor(EVec4& color) {
    register float* dest = &m_color.x;
    *dest++ = color.x;
    *dest++ = color.y;
    *dest++ = color.z;
    *dest = color.w;
}
