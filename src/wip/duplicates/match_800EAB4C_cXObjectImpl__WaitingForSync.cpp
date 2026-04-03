// 0x800EAB4C (8 bytes)
class cXObjectImpl {
public:
    int WaitingForSync();
};

int cXObjectImpl::WaitingForSync() {
    return *(int*)((char*)this + 0xE4);
}
