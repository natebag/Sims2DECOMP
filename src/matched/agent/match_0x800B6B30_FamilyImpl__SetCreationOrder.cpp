/* FamilyImpl::SetCreationOrder(int) at 0x800B6B30 (8B) */

struct FamilyImpl {
    char pad[0x10];
    int m_creationOrder;

    void SetCreationOrder(int n);
};

void FamilyImpl::SetCreationOrder(int n) {
    m_creationOrder = n;
}
