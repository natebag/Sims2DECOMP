// 0x80145668 RoutingSlot::SetAllowDifferentAlts(bool) (32B) — bit 0x8000

struct RoutingSlot {
    char pad[28];
    int m_flags;
    void SetAllowDifferentAlts(bool b);
};

void RoutingSlot::SetAllowDifferentAlts(bool b) {
    m_flags &= ~0x8000;
    if (!b) return;
    m_flags |= 0x8000;
}
