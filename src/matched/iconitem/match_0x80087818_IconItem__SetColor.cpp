// 0x80087818 IconItem::SetColor(EVec4&) (40B)

struct EVec4 {
    int x;
    int y;
    int z;
    float w;
};

struct IconItem {
    char pad0[32];
    EVec4 m_color;
    void SetColor(EVec4& c);
};

void IconItem::SetColor(EVec4& c) {
    EVec4* dst = &m_color;
    int x = c.x;
    int y = c.y;
    int z = c.z;
    m_color.x = x;
    *(volatile int*)&dst->z = z;
    *(volatile int*)&dst->y = y;
    m_color.w = c.w;
}
