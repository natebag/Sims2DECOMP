// 0x8014552C RoutingSlot::IsFacingAwayFromObject() const (20B)
// Pattern: subfic,-1 + adde = (facing == 1)

struct RoutingSlot {
    char pad[52];
    int m_facing;
    int IsFacingAwayFromObject() const;
};

int RoutingSlot::IsFacingAwayFromObject() const {
    return (-1 - m_facing) == 0;
}
