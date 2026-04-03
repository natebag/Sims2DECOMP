// 0x800EB3EC (8 bytes)
class cXObjectImpl {
public:
    int GetRelMatrix();
};

int cXObjectImpl::GetRelMatrix() {
    return *(int*)((char*)this + 0x60);
}
