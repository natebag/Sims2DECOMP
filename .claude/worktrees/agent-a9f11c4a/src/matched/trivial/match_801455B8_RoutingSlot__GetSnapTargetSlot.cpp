// 0x801455B8 (8 bytes)
class RoutingSlot {
public:
    int GetSnapTargetSlot();
};

int RoutingSlot::GetSnapTargetSlot() {
    return *(int*)((char*)this + 0x20);
}
