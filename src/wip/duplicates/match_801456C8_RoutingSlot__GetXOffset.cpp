// 0x801456C8 (8 bytes)
class RoutingSlot {
public:
    float GetXOffset();
};

float RoutingSlot::GetXOffset() {
    return *(float*)((char*)this + 0x4);
}
