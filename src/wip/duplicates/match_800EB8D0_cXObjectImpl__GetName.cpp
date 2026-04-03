// 0x800EB8D0 (8 bytes)
class cXObjectImpl {
public:
    int GetName();
};

int cXObjectImpl::GetName() {
    return *(int*)((char*)(*(int*)((char*)this + 0x8C)) + 0x14);
}
