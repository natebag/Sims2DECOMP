// 0x801456B4 (12 bytes)
// RoutingSlot::GetUseAverageObjectLocation(void) const
// lhz r3, 28(r3); rlwinm r3, r3, 0, 31, 31; blr
struct Slot;

class RoutingSlot {
public:
    char m_pad[28];
    unsigned short m_flags;
    int GetUseAverageObjectLocation() const;
};

int RoutingSlot::GetUseAverageObjectLocation() const {
    return m_flags & 1;
}
