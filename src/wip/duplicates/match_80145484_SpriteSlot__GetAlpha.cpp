// 0x80145484 (8 bytes)
class SpriteSlot {
public:
    float GetAlpha();
};

float SpriteSlot::GetAlpha() {
    return *(float*)((char*)this + 0x58);
}
