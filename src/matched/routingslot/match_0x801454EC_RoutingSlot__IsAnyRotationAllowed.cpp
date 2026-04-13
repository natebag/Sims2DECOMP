// 0x801454EC RoutingSlot::IsAnyRotationAllowed (24B)

struct RoutingSlot_IARA {
    char pad[0x1C];
    int m_flags;
    int IsAnyRotationAllowed() const;
};

int RoutingSlot_IARA::IsAnyRotationAllowed() const {
    int r = 1;
    if ((m_flags & 0x100) == 0) r = 0;
    return r;
}
