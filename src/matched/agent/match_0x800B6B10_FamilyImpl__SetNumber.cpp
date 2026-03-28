/* FamilyImpl::SetNumber(int) at 0x800B6B10 (8B) */

struct FamilyImpl {
    char pad[0x08];
    int m_number;

    void SetNumber(int n);
};

void FamilyImpl::SetNumber(int n) {
    m_number = n;
}
