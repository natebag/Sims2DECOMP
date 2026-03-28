// 0x800EB844 (8 bytes)
class cXObjectImpl {
public:
    int GetNextImpl();
};

int cXObjectImpl::GetNextImpl() {
    return *(int*)((char*)this + 0x5C);
}
