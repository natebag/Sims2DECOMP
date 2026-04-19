// FLAGS: -fno-schedule-insns
/* FamilyImpl::SetJustMovedIn(bool) at 0x800B6BD8 (32B) */

struct FamilyImpl_SJM {
    char m_pad[52];
    int m_flags;
    void SetJustMovedIn(int val);
};

void FamilyImpl_SJM::SetJustMovedIn(int val) {
    m_flags &= ~4;
    if (val) {
        m_flags |= 4;
    }
}
