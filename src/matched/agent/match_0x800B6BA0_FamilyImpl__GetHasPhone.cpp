/* FamilyImpl::GetHasPhone(void) at 0x800B6BA0 (12B) */

struct FamilyImpl {
    char pad[0x34];
    unsigned int m_flags;

    int GetHasPhone(void);
};

int FamilyImpl::GetHasPhone(void) {
    return m_flags & 1;
}
