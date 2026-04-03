// 0x80145540 (8 bytes)
class RoutingSlot {
public:
    int GetFacingDirection();
};

int RoutingSlot::GetFacingDirection() {
    return *(int*)((char*)this + 0x34);
}
