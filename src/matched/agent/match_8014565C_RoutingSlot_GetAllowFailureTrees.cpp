// 0x8014565C (12 bytes)
// RoutingSlot::GetAllowFailureTrees(void) const
// lwz r3, 28(r3); rlwinm r3, r3, 18, 31, 31; blr
struct Slot;

class RoutingSlot {
public:
    char m_pad[28];
    int m_flags;
    int GetAllowFailureTrees() const;
};

int RoutingSlot::GetAllowFailureTrees() const {
    return (m_flags >> 14) & 1;
}
