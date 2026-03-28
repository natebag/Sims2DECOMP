// 0x80145688 (12 bytes)
// RoutingSlot::GetAllowDifferentAlts(void) const
// lwz r3, 28(r3); rlwinm r3, r3, 17, 31, 31; blr
class RoutingSlot {
public:
    char m_pad[28];
    int m_flags;
    int GetAllowDifferentAlts() const;
};

int RoutingSlot::GetAllowDifferentAlts() const {
    return (m_flags >> 15) & 1;
}
