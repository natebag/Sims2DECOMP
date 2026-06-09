/* FamilyImpl::SetHouseNumber(int) at 0x800B6B20 (8B) */

struct FamilyImpl {
    char pad[0x0C];
    int m_houseNumber;

    void SetHouseNumber(int n);
};

void FamilyImpl::SetHouseNumber(int n) {
    m_houseNumber = n;
}
