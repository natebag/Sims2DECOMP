// 0x80145430 (8 bytes)
class SpriteSlot {
public:
    void SetPriority(int p);
};

void SpriteSlot::SetPriority(int p) {
    *(int*)((char*)this + 0x44) = p;
}
