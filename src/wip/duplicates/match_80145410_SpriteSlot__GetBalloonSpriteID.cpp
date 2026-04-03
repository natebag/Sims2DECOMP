// 0x80145410 (8 bytes)
class SpriteSlot {
public:
    int GetBalloonSpriteID();
};

int SpriteSlot::GetBalloonSpriteID() {
    return *(int*)((char*)this + 0x3C);
}
