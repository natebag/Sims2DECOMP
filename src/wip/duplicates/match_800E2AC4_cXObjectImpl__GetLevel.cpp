// 0x800E2AC4 (8 bytes)
class cXObjectImpl {
public:
    int GetLevel();
};

int cXObjectImpl::GetLevel() {
    return *(int*)((char*)this + 0x80);
}
