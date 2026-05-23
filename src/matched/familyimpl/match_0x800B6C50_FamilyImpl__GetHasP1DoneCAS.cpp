/* FamilyImpl::GetHasP1DoneCAS(void) at 0x800B6C50 (12B) */

struct FamilyImpl {
    char pad[0x34];
    unsigned int m_flags;

    int GetHasP1DoneCAS(void);
};

int FamilyImpl::GetHasP1DoneCAS(void) {
    return (m_flags >> 4) & 1;
}
