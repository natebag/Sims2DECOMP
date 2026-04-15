/* FamilyImpl::SetJustMovedIn(bool) - 0x800B6BD8 (32 bytes) */

class FamilyImpl {
public:
    char pad[52];
    int m_flags;

    void SetJustMovedIn(int v);
};

void FamilyImpl::SetJustMovedIn(int v) {
    int f = m_flags;
    f &= ~4;
    m_flags = f;
    if (v) {
        m_flags = f | 4;
    }
}
