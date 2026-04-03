/* FamilyImpl::GetHouseValue(void) at 0x800B6B60 (8B) */

struct FamilyImpl {
    char pad[0x18];
    int m_houseValue;

    int GetHouseValue(void);
};

int FamilyImpl::GetHouseValue(void) {
    return m_houseValue;
}
