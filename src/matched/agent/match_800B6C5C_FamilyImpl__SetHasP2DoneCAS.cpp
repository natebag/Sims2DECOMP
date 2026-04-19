// FLAGS: -fno-schedule-insns
/* FamilyImpl::SetHasP2DoneCAS(bool) at 0x800B6C5C (32B) */

struct FamilyImpl_SHP2 {
    char m_pad[52];
    int m_flags;
    void SetHasP2DoneCAS(int val);
};

void FamilyImpl_SHP2::SetHasP2DoneCAS(int val) {
    m_flags &= ~32;
    if (val) {
        m_flags |= 32;
    }
}
