// 0x8014547C (8 bytes)
class SpriteSlot {
public:
    float GetSizeMultiplierY();
};

float SpriteSlot::GetSizeMultiplierY() {
    return *(float*)((char*)this + 0x54);
}
