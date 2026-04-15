/* FamilyImpl::SetHasP1DoneCAS(bool) - 0x800B6C30 (32 bytes) */

class FamilyImpl {
public:
    char pad[52];
    int m_flags;

    void SetHasP1DoneCAS(int v);
};

void FamilyImpl::SetHasP1DoneCAS(int v) {
    int f = m_flags;
    f &= ~16;
    m_flags = f;
    if (v) {
        m_flags = f | 16;
    }
}
