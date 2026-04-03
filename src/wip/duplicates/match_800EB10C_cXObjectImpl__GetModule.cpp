// 0x800EB10C (8 bytes)
class cXObjectImpl {
public:
    int GetModule();
};

int cXObjectImpl::GetModule() {
    return *(int*)((char*)this + 0x58);
}
