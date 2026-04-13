// 0x80145548 RoutingSlot::GetIgnoreRooms (24B)

struct RoutingSlot_GIR {
    char pad[0x1C];
    int m_flags;
    int GetIgnoreRooms() const;
};

int RoutingSlot_GIR::GetIgnoreRooms() const {
    int r = 1;
    if ((m_flags & 0x800) == 0) r = 0;
    return r;
}
