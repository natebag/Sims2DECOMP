// 0x801455C0 RoutingSlot::SnapsToDirection (24b)
struct RoutingSlot {
    char pad[0x1C];
    int m_flags;
    int SnapsToDirection() const;
};

int RoutingSlot::SnapsToDirection() const {
    int result = 1;
    if (m_flags & 0x1000) return result;
    result = 0;
    return result;
}
