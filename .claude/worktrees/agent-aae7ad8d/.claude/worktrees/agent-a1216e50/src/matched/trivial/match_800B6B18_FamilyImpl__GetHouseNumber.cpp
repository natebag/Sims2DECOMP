// 0x800B6B18 (8 bytes)
class FamilyImpl {
public:
    int GetHouseNumber();
};

int FamilyImpl::GetHouseNumber() {
    return *(int*)((char*)this + 0xC);
}
