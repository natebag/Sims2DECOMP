// FLAGS: -fno-schedule-insns
/* FamilyImpl::SetHasP1DoneCAS(bool) at 0x800B6C30 (32B) */

struct FamilyImpl_SHP1 {
    char m_pad[52];
    int m_flags;
    void SetHasP1DoneCAS(int val);
};

void FamilyImpl_SHP1::SetHasP1DoneCAS(int val) {
    m_flags &= ~16;
    if (val) {
        m_flags |= 16;
    }
}
