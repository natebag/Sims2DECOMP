// 0x801453CC (8 bytes)
class SpriteSlot {
public:
    void UseBalloonSprite(int p);
};

void SpriteSlot::UseBalloonSprite(int p) {
    *(int*)((char*)this + 0x3C) = p;
}
