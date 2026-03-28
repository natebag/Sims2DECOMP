// 0x8014546C (8 bytes)
class SpriteSlot {
public:
    void SetAltOffset(float p);
};

void SpriteSlot::SetAltOffset(float p) {
    *(float*)((char*)this + 0xC) = p;
}
