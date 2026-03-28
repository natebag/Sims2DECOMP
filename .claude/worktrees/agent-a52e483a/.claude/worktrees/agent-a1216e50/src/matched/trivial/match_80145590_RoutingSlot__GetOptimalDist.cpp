// 0x80145590 (8 bytes)
class RoutingSlot {
public:
    int GetOptimalDist();
};

int RoutingSlot::GetOptimalDist() {
    return *(int*)((char*)this + 0x2C);
}
