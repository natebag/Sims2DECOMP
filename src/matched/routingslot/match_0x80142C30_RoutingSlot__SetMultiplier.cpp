/* RoutingSlot::SetMultiplier(RoutingSlot::VerticalPosition, int) - 0x80142C30 (16 bytes) */

class RoutingSlot {
public:
    char pad[16];
    int m_multipliers[8];

    void SetMultiplier(int pos, int val);
};

void RoutingSlot::SetMultiplier(int pos, int val) {
    m_multipliers[pos] = val;
}
