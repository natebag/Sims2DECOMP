// 0x803A08C4 PaneItem::SetSizeY(float) (20B)
// store float @24, clear bit 1 of flags @4

struct PaneItem {
    char pad[4];
    int m_flags;    // +4
    char pad2[16];
    float m_sizeY;  // +24
    void SetSizeY(float v);
};

void PaneItem::SetSizeY(float v) {
    m_sizeY = v;
    m_flags &= ~2;
}
