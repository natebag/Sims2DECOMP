// 0x80145518 RoutingSlot::IsFacingTowardsObject() const (20B)
// Pattern: subfic,-2 + adde = (facing == 2)

struct RoutingSlot {
    char pad[52];
    int m_facing;
    int IsFacingTowardsObject() const;
};

int RoutingSlot::IsFacingTowardsObject() const {
    return (-2 - m_facing) == 0;
}
