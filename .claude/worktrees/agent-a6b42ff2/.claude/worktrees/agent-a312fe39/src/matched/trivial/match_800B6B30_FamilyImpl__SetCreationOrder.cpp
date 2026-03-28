// 0x800B6B30 (8 bytes)
class FamilyImpl {
public:
    void SetCreationOrder(int p);
};

void FamilyImpl::SetCreationOrder(int p) {
    *(int*)((char*)this + 0x10) = p;
}
