// 0x801456D0 (8 bytes)
class RoutingSlot {
public:
    float GetYOffset();
};

float RoutingSlot::GetYOffset() {
    return *(float*)((char*)this + 0x8);
}
