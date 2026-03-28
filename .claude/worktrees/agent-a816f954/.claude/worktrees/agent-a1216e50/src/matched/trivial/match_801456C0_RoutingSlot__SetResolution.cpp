// 0x801456C0 (8 bytes)
class RoutingSlot {
public:
    void SetResolution(int p);
};

void RoutingSlot::SetResolution(int p) {
    *(int*)((char*)this + 0x38) = p;
}
