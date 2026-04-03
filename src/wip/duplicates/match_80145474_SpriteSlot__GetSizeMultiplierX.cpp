// 0x80145474 (8 bytes)
class SpriteSlot {
public:
    float GetSizeMultiplierX();
};

float SpriteSlot::GetSizeMultiplierX() {
    return *(float*)((char*)this + 0x50);
}
