// 0x800B6B60 (8 bytes)
class FamilyImpl {
public:
    int GetHouseValue();
};

int FamilyImpl::GetHouseValue() {
    return *(int*)((char*)this + 0x18);
}
