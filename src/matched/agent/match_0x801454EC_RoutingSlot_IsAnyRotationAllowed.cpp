// 0x801454EC RoutingSlot::IsAnyRotationAllowed (24b)
struct RoutingSlot {
    char pad[0x1C];
    int m_flags;
    int IsAnyRotationAllowed() const;
};

int RoutingSlot::IsAnyRotationAllowed() const {
    int result = 1;
    if (m_flags & 0x100) return result;
    result = 0;
    return result;
}
