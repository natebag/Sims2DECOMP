// 0x801453E4 (8 bytes)
class SpriteSlot {
public:
    void SetPopSize(float p);
};

void SpriteSlot::SetPopSize(float p) {
    *(float*)((char*)this + 0x5C) = p;
}
