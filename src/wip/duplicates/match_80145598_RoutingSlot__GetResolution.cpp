// 0x80145598 (8 bytes)
class RoutingSlot {
public:
    int GetResolution();
};

int RoutingSlot::GetResolution() {
    return *(int*)((char*)this + 0x38);
}
