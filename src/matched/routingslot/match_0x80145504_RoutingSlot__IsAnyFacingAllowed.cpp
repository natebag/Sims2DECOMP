/* RoutingSlot::IsAnyFacingAllowed(void) const - 0x80145504 (20 bytes) */
class RoutingSlot {
public:
    char pad[52];
    int m_facing;
    int IsAnyFacingAllowed(void) const;
};
int RoutingSlot::IsAnyFacingAllowed(void) const {
    return m_facing == -3;
}
