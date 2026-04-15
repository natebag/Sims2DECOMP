/* FamilyImpl::SetHasBaby(bool) - 0x800B6BAC (32 bytes) */

class FamilyImpl {
public:
    char pad[52];
    int m_flags;

    void SetHasBaby(int v);
};

void FamilyImpl::SetHasBaby(int v) {
    int f = m_flags;
    f &= ~2;
    m_flags = f;
    if (v) {
        m_flags = f | 2;
    }
}
