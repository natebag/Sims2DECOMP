/* FamilyImpl::GetHasP2DoneCAS(void) at 0x800B6C7C (12B) */

struct FamilyImpl {
    char pad[0x34];
    unsigned int m_flags;

    int GetHasP2DoneCAS(void);
};

int FamilyImpl::GetHasP2DoneCAS(void) {
    return (m_flags >> 5) & 1;
}
