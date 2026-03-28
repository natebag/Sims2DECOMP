/* FamilyImpl::SetHouseValue(int) at 0x800B6B68 (8B) */

struct FamilyImpl {
    char pad[0x18];
    int m_houseValue;

    void SetHouseValue(int v);
};

void FamilyImpl::SetHouseValue(int v) {
    m_houseValue = v;
}
