// 0x80145560 RoutingSlot::SetIgnoreRooms(bool) (32B) — bit 0x0800

struct RoutingSlot {
    char pad[28];
    int m_flags;
    void SetIgnoreRooms(bool b);
};

void RoutingSlot::SetIgnoreRooms(bool b) {
    m_flags &= ~0x0800;
    if (!b) return;
    m_flags |= 0x0800;
}
