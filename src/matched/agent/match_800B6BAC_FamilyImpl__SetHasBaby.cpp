// FLAGS: -fno-schedule-insns
/* FamilyImpl::SetHasBaby(bool) at 0x800B6BAC (32B) */

struct FamilyImpl_SHB {
    char m_pad[52];
    int m_flags;
    void SetHasBaby(int val);
};

void FamilyImpl_SHB::SetHasBaby(int val) {
    m_flags &= ~2;
    if (val) {
        m_flags |= 2;
    }
}
