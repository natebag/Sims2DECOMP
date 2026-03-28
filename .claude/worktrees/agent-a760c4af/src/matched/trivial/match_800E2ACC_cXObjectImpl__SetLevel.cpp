// 0x800E2ACC (8 bytes)
class cXObjectImpl {
public:
    void SetLevel(int p);
};

void cXObjectImpl::SetLevel(int p) {
    *(int*)((char*)this + 0x80) = p;
}
