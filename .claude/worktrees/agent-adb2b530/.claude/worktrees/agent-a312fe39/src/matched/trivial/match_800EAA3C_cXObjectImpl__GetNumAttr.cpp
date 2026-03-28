// 0x800EAA3C (8 bytes)
class cXObjectImpl {
public:
    int GetNumAttr();
};

int cXObjectImpl::GetNumAttr() {
    return *(int*)((char*)this + 0xC);
}
