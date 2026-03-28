// 0x80145438 (8 bytes)
class SpriteSlot {
public:
    int GetPriority();
};

int SpriteSlot::GetPriority() {
    return *(int*)((char*)this + 0x44);
}
