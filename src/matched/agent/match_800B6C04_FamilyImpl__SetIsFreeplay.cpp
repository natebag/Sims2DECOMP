// FLAGS: -fno-schedule-insns
/* FamilyImpl::SetIsFreeplay(bool) at 0x800B6C04 (32B) */

struct FamilyImpl_SIF {
    char m_pad[52];
    int m_flags;
    void SetIsFreeplay(int val);
};

void FamilyImpl_SIF::SetIsFreeplay(int val) {
    m_flags &= ~8;
    if (val) {
        m_flags |= 8;
    }
}
