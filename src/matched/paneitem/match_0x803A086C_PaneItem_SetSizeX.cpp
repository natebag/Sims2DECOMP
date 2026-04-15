// 0x803A086C PaneItem::SetSizeX(float) (20B)
// store float @20, clear bit 1 of flags @4

struct PaneItem {
    char pad[4];
    int m_flags;    // +4
    char pad2[12];
    float m_sizeX;  // +20
    void SetSizeX(float v);
};

void PaneItem::SetSizeX(float v) {
    m_sizeX = v;
    m_flags &= ~2;
}
