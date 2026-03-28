// 0x800EB330 (8 bytes)
class cXObjectImpl {
public:
    int GetSelector();
};

int cXObjectImpl::GetSelector() {
    return *(int*)((char*)this + 0x8C);
}
