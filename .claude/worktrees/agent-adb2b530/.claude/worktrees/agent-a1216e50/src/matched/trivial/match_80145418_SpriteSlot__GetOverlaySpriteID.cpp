// 0x80145418 (8 bytes)
class SpriteSlot {
public:
    int GetOverlaySpriteID();
};

int SpriteSlot::GetOverlaySpriteID() {
    return *(int*)((char*)this + 0x40);
}
