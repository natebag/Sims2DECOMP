/* RoutingSlot::FaceTowardsObject - 0x80142BA0 (12 bytes) */

class RoutingSlot {
public:
    char pad[0x34];
    int m_facing;
    void FaceTowardsObject();
};

void RoutingSlot::FaceTowardsObject() {
    m_facing = -2;
}
