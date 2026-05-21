// 0x80142BD8 (88B) RoutingSlot::SetTileDistances(float, float, float)

extern float RoutingSlot_distScale[3];  // 0x803DD6E8

class RoutingSlot {
public:
    void SetTileDistances(float a, float b, float c);
};

void RoutingSlot::SetTileDistances(float a, float b, float c) {
    float scale = RoutingSlot_distScale[0];
    *(int*)((char*)this + 36) = (int)(a * scale);
    *(int*)((char*)this + 40) = (int)(b * scale);
    *(int*)((char*)this + 44) = (int)(c * scale);
}
