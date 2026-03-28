// 0x800B6B20 (8 bytes)
class FamilyImpl {
public:
    void SetHouseNumber(int p);
};

void FamilyImpl::SetHouseNumber(int p) {
    *(int*)((char*)this + 0xC) = p;
}
