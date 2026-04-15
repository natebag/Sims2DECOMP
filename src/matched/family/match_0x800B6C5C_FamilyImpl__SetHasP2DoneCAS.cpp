/* FamilyImpl::SetHasP2DoneCAS(bool) - 0x800B6C5C (32 bytes) */

class FamilyImpl {
public:
    char pad[52];
    int m_flags;

    void SetHasP2DoneCAS(int v);
};

void FamilyImpl::SetHasP2DoneCAS(int v) {
    int f = m_flags;
    f &= ~32;
    m_flags = f;
    if (v) {
        m_flags = f | 32;
    }
}
