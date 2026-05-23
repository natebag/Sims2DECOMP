// RoutingSlot::GetSnapDirection(void) const - 0x801455D8 (44B)
// Linear scan of 7-bit direction mask at offset 0x1c. Returns first set bit index, or 0.

class RoutingSlot {
public:
    char _pad[0x1c];
    int m_dirMask;
    int GetSnapDirection() const;
};

int RoutingSlot::GetSnapDirection() const
{
    int dir = m_dirMask;
    for (int i = 0; i < 7; i++) {
        if ((dir >> i) & 1) return i;
    }
    return 0;
}
