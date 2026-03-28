/* RoutingSlot::SetIsOnTopOfObject - 0x80142B54 (16 bytes) */

class RoutingSlot {
public:
    char pad[0x1C];
    int m_flags;
    void SetIsOnTopOfObject();
};

void RoutingSlot::SetIsOnTopOfObject() {
    m_flags = m_flags & 0xFFFFFF00;
}
