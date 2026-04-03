// 0x800EB2CC (8 bytes)
class cXObjectImpl {
public:
    int GetDef();
};

int cXObjectImpl::GetDef() {
    return *(int*)((char*)this + 0x88);
}
