/* RoutingSlot::SetHasRandomScoring(bool) at 0x8014561C (32B) */

class RoutingSlot {
public:
    char m_pad[28];
    int m_flags;
    void SetHasRandomScoring(int val);
};

void RoutingSlot::SetHasRandomScoring(int val) {
    m_flags &= ~0x2000;
    if (val) {
        m_flags |= 0x2000;
    }
}
