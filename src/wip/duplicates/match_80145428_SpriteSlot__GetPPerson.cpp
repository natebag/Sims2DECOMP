// 0x80145428 (8 bytes)
class SpriteSlot {
public:
    int GetPPerson();
};

int SpriteSlot::GetPPerson() {
    return *(int*)((char*)this + 0x64);
}
