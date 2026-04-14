/* RoutingSlot::FaceAwayFromObject - 0x80142BAC (12 bytes) */

class RoutingSlot {
public:
    char pad[0x34];
    int m_facing;
    void FaceAwayFromObject();
};

void RoutingSlot::FaceAwayFromObject() {
    m_facing = -1;
}
