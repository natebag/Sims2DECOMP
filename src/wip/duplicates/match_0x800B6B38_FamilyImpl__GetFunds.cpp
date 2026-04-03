/* FamilyImpl::GetFunds(void) at 0x800B6B38 (8B) */

struct FamilyImpl {
    char pad[0x14];
    int m_funds;

    int GetFunds(void);
};

int FamilyImpl::GetFunds(void) {
    return m_funds;
}
