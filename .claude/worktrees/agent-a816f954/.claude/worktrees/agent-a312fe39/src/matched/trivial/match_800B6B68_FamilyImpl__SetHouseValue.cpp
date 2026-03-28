// 0x800B6B68 (8 bytes)
class FamilyImpl {
public:
    void SetHouseValue(int p);
};

void FamilyImpl::SetHouseValue(int p) {
    *(int*)((char*)this + 0x18) = p;
}
