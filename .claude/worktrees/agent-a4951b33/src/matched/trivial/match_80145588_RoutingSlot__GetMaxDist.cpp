// 0x80145588 (8 bytes)
class RoutingSlot {
public:
    int GetMaxDist();
};

int RoutingSlot::GetMaxDist() {
    return *(int*)((char*)this + 0x28);
}
