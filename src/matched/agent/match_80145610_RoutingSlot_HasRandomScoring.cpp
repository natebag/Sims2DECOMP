// 0x80145610 (12 bytes)
// RoutingSlot::HasRandomScoring(void) const
// lwz r3, 28(r3); rlwinm r3, r3, 19, 31, 31; blr
class RoutingSlot {
public:
    char m_pad[28];
    int m_flags;
    int HasRandomScoring() const;
};

int RoutingSlot::HasRandomScoring() const {
    return (m_flags >> 13) & 1;
}
