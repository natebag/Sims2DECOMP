// 0x80145464 (8 bytes)
class SpriteSlot {
public:
    float GetAltOffset();
};

float SpriteSlot::GetAltOffset() {
    return *(float*)((char*)this + 0xC);
}
