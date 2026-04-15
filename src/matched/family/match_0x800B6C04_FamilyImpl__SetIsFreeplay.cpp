/* FamilyImpl::SetIsFreeplay(bool) - 0x800B6C04 (32 bytes) */

class FamilyImpl {
public:
    char pad[52];
    int m_flags;

    void SetIsFreeplay(int v);
};

void FamilyImpl::SetIsFreeplay(int v) {
    int f = m_flags;
    f &= ~8;
    m_flags = f;
    if (v) {
        m_flags = f | 8;
    }
}
