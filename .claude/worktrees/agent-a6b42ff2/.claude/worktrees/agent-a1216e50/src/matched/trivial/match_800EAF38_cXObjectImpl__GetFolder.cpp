// 0x800EAF38 (8 bytes)
class cXObjectImpl {
public:
    int GetFolder();
};

int cXObjectImpl::GetFolder() {
    return *(int*)((char*)(*(int*)((char*)this + 0x8C)) + 0x50);
}
