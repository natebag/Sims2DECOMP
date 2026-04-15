/* FamilyImpl::SetHasPhone(bool) - 0x800B6B80 (32 bytes) */

class FamilyImpl {
public:
    char pad[52];
    int m_flags;

    void SetHasPhone(int v);
};

void FamilyImpl::SetHasPhone(int v) {
    int f = m_flags;
    f &= ~1;
    m_flags = f;
    if (v) {
        m_flags = f | 1;
    }
}
