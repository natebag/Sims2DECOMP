// 0x801456D8 (8 bytes)
class RoutingSlot {
public:
    float GetAltOffset();
};

float RoutingSlot::GetAltOffset() {
    return *(float*)((char*)this + 0xC);
}
