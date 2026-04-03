// 0x800B6B38 (8 bytes)
class FamilyImpl {
public:
    int GetFunds();
};

int FamilyImpl::GetFunds() {
    return *(int*)((char*)this + 0x14);
}
