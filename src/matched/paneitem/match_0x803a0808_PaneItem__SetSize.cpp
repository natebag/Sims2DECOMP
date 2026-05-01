// 0x803A0808 PaneItem::SetSize (32B)

struct EVec2 { int y, x; };

struct PaneItem {
    int m_type;
    int m_flags;
    char pad[12];
    EVec2 m_size;
    void SetSize(EVec2& v);
};

void PaneItem::SetSize(EVec2& v) {
    int y = v.y;
    int x = v.x;
    m_flags &= ~2;
    m_size.x = x;
    m_size.y = y;
}
