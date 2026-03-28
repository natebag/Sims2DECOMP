// 0x80145604 (12 bytes)
// RoutingSlot::Absolute(void) const
// lwz r3, 28(r3); rlwinm r3, r3, 23, 31, 31; blr
struct Slot;

class RoutingSlot {
public:
    char m_pad[28];
    int m_flags;
    int Absolute() const;
};

int RoutingSlot::Absolute() const {
    return (m_flags >> 9) & 1;
}
