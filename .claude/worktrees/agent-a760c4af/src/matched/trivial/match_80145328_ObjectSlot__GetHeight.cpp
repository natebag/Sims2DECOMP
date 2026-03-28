// 0x80145328 (8 bytes)
class ObjectSlot {
public:
    int GetHeight();
};

int ObjectSlot::GetHeight() {
    return *(int*)((char*)this + 0x8);
}
