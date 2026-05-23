/* FamilyImpl::GetHasBaby(void) at 0x800B6BCC (12B) */

struct FamilyImpl {
    char pad[0x34];
    unsigned int m_flags;

    int GetHasBaby(void);
};

int FamilyImpl::GetHasBaby(void) {
    return (m_flags >> 1) & 1;
}
