// 0x800EB338 (8 bytes)
class cXObjectImpl {
public:
    int GetBehavior();
};

int cXObjectImpl::GetBehavior() {
    return *(int*)((char*)(*(int*)((char*)this + 0x8C)) + 0xC);
}
