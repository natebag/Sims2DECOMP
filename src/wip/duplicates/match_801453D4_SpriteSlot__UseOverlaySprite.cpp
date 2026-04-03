// 0x801453D4 (8 bytes)
class SpriteSlot {
public:
    void UseOverlaySprite(int p);
};

void SpriteSlot::UseOverlaySprite(int p) {
    *(int*)((char*)this + 0x40) = p;
}
