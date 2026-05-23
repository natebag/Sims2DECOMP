/* FamilyImpl::GetJustMovedIn(void) at 0x800B6BF8 (12B) */

struct FamilyImpl {
    char pad[0x34];
    unsigned int m_flags;

    int GetJustMovedIn(void);
};

int FamilyImpl::GetJustMovedIn(void) {
    return (m_flags >> 2) & 1;
}
