/* RoutingSlot::AllowAnyRotation - 0x80142B84 (16 bytes) */

class RoutingSlot {
public:
    char pad[0x1C];
    int m_flags;
    void AllowAnyRotation();
};

void RoutingSlot::AllowAnyRotation() {
    m_flags = m_flags | 0x100;
}
