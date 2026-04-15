/* RoutingSlot::SetFacingDirection(int) - 0x80142BB8 (16 bytes) */

class RoutingSlot {
public:
    char pad[52];
    int m_facingDirection;

    void SetFacingDirection(int dir);
};

void RoutingSlot::SetFacingDirection(int dir) {
    if ((unsigned)dir > 7) return;
    m_facingDirection = dir;
}
