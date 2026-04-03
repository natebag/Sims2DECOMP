// 0x800EAB38 (8 bytes)
class cXObjectImpl {
public:
    int GetSyncObject();
};

int cXObjectImpl::GetSyncObject() {
    return *(int*)((char*)this + 0xDC);
}
