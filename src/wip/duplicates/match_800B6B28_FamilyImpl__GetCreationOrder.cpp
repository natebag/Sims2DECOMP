// 0x800B6B28 (8 bytes)
class FamilyImpl {
public:
    int GetCreationOrder();
};

int FamilyImpl::GetCreationOrder() {
    return *(int*)((char*)this + 0x10);
}
