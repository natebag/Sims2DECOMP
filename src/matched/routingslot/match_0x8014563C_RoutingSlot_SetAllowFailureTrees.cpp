// 0x8014563C RoutingSlot::SetAllowFailureTrees(bool) (32B) — bit 0x4000

struct RoutingSlot {
    char pad[28];
    int m_flags;
    void SetAllowFailureTrees(bool b);
};

void RoutingSlot::SetAllowFailureTrees(bool b) {
    m_flags &= ~0x4000;
    if (!b) return;
    m_flags |= 0x4000;
}
