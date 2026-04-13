// 0x801455C0 RoutingSlot::SnapsToDirection (24B)

struct RoutingSlot_STD {
    char pad[0x1C];
    int m_flags;
    int SnapsToDirection() const;
};

int RoutingSlot_STD::SnapsToDirection() const {
    int r = 1;
    if ((m_flags & 0x1000) == 0) r = 0;
    return r;
}
