/* RoutingSlot::IsDirectionAllowed(int) const - 0x801454D0 (28 bytes) */

class RoutingSlot {
public:
    char pad[28];
    int m_allowedMask;

    int IsDirectionAllowed(int dir) const;
};

int RoutingSlot::IsDirectionAllowed(int dir) const {
    int shifted = m_allowedMask >> dir;
    if ((shifted & 1) != 0) return 1;
    return 0;
}
