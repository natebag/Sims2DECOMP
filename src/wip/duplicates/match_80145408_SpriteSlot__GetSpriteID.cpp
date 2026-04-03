// 0x80145408 (8 bytes)
class SpriteSlot {
public:
    int GetSpriteID();
};

int SpriteSlot::GetSpriteID() {
    return *(int*)((char*)this + 0x18);
}
