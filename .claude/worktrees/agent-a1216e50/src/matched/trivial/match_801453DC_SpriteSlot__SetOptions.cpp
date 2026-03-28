// 0x801453DC (8 bytes)
class SpriteSlot {
public:
    void SetOptions(int p);
};

void SpriteSlot::SetOptions(int p) {
    *(int*)((char*)this + 0x48) = p;
}
