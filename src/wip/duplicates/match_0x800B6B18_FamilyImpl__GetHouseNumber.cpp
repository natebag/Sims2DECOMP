/* FamilyImpl::GetHouseNumber(void) at 0x800B6B18 (8B) */

struct FamilyImpl {
    char pad[0x0C];
    int m_houseNumber;

    int GetHouseNumber(void);
};

int FamilyImpl::GetHouseNumber(void) {
    return m_houseNumber;
}
