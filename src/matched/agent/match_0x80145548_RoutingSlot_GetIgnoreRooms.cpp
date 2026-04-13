// 0x80145548 RoutingSlot::GetIgnoreRooms (24b)
struct RoutingSlot {
    char pad[0x1C];
    int m_flags;
    int GetIgnoreRooms() const;
};

int RoutingSlot::GetIgnoreRooms() const {
    int result = 1;
    if (m_flags & 0x800) return result;
    result = 0;
    return result;
}
