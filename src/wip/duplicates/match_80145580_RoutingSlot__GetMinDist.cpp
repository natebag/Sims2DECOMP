// 0x80145580 (8 bytes)
class RoutingSlot {
public:
    int GetMinDist();
};

int RoutingSlot::GetMinDist() {
    return *(int*)((char*)this + 0x24);
}
