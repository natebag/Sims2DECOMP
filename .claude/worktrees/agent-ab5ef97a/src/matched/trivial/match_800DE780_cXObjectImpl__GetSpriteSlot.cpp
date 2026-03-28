// 0x800DE780 (8 bytes)
class cXObjectImpl {
public:
    int GetSpriteSlot();
};

int cXObjectImpl::GetSpriteSlot() {
    return *(int*)((char*)this + 0xB0);
}
