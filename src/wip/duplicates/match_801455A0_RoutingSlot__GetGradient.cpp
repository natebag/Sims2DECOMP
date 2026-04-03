// 0x801455A0 (8 bytes)
class RoutingSlot {
public:
    float GetGradient();
};

float RoutingSlot::GetGradient() {
    return *(float*)((char*)this + 0x30);
}
