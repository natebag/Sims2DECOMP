/* FamilyImpl::GetIsFreeplay(void) at 0x800B6C24 (12B) */

struct FamilyImpl {
    char pad[0x34];
    unsigned int m_flags;

    int GetIsFreeplay(void);
};

int FamilyImpl::GetIsFreeplay(void) {
    return (m_flags >> 3) & 1;
}
