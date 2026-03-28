/* FamilyImpl::GetNumber(void) at 0x800B6B08 (8B) */

struct FamilyImpl {
    char pad[0x08];
    int m_number;

    int GetNumber(void);
};

int FamilyImpl::GetNumber(void) {
    return m_number;
}
