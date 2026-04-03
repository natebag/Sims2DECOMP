/* FamilyImpl::GetCreationOrder(void) at 0x800B6B28 (8B) */

struct FamilyImpl {
    char pad[0x10];
    int m_creationOrder;

    int GetCreationOrder(void);
};

int FamilyImpl::GetCreationOrder(void) {
    return m_creationOrder;
}
