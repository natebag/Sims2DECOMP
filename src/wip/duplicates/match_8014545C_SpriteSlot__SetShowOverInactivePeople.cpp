// 0x8014545C (8 bytes)
class SpriteSlot {
public:
    void SetShowOverInactivePeople(int p);
};

void SpriteSlot::SetShowOverInactivePeople(int p) {
    *(int*)((char*)this + 0x60) = p;
}
