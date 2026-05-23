// FLAGS: -fno-elide-constructors
// 0x80317A00 ERFont::SetColor (40 bytes)
// DOL:
//   lfs f13, 0(r4)
//   addi r9, r3, 88        ; r9 = &m_color
//   stfs f13, 88(r3)       ; first store via direct base+offset
//   lfs f0, 4(r4)
//   stfs f0, 4(r9)         ; subsequent stores via r9 (sub-object pattern)
//   lfs f13, 8(r4)
//   stfs f13, 8(r9)
//   lfs f0, 12(r4)
//   stfs f0, 12(r9)
//   blr

struct EVec4 {
    float x, y, z, w;
};

struct ERFont {
    char pad[0x58];
    EVec4 m_color;

    void SetColor(EVec4& color);
};

void ERFont::SetColor(EVec4& color) {
    m_color.x = color.x;
    EVec4* dst = &m_color;
    dst->y = color.y;
    dst->z = color.z;
    dst->w = color.w;
}
