// 0x80145454 (8 bytes)
class SpriteSlot {
public:
    int GetShowOverInactivePeople();
};

int SpriteSlot::GetShowOverInactivePeople() {
    return *(int*)((char*)this + 0x60);
}
