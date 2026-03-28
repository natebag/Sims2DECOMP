// 0x800B6B08 (8 bytes)
class FamilyImpl {
public:
    int GetNumber();
};

int FamilyImpl::GetNumber() {
    return *(int*)((char*)this + 0x8);
}
