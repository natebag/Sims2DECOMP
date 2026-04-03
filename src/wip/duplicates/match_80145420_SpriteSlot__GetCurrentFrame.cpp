// 0x80145420 (8 bytes)
class SpriteSlot {
public:
    int GetCurrentFrame();
};

int SpriteSlot::GetCurrentFrame() {
    return *(int*)((char*)this + 0x30);
}
