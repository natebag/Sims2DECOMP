/* FamilyImpl::ClearFamily(void) at 0x800B6530 (24B) */

struct FamilyImpl {
    char pad[0x0C];
    int m_houseNumber;
    char pad2[0x04];
    int m_funds;
    int m_houseValue;
    int m_friendCount;

    void ClearFamily(void);
};

void FamilyImpl::ClearFamily(void) {
    m_houseNumber = 0;
    m_funds = 0;
    m_houseValue = 0;
    m_friendCount = 0;
}
