// 0x80145694 RoutingSlot::SetUseAverageObjectLocation(bool) (32B) — bit 0x10000

struct RoutingSlot {
    char pad[28];
    int m_flags;
    void SetUseAverageObjectLocation(bool b);
};

void RoutingSlot::SetUseAverageObjectLocation(bool b) {
    m_flags &= ~0x10000;
    if (!b) return;
    m_flags |= 0x10000;
}
