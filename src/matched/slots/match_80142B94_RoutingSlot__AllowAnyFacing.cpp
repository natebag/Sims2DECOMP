/* RoutingSlot::AllowAnyFacing - 0x80142B94 (12 bytes) */

class RoutingSlot {
public:
    char pad[0x34];
    int m_facing;
    void AllowAnyFacing();
};

void RoutingSlot::AllowAnyFacing() {
    m_facing = -3;
}
