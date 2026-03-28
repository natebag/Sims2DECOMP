// 0x80145440 (8 bytes)
class SpriteSlot {
public:
    int GetOptions();
};

int SpriteSlot::GetOptions() {
    return *(int*)((char*)this + 0x48);
}
