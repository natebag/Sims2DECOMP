// 0x800B63A4 FamilyImpl::GetIndexedMember(int) (52B)

struct FamilyImpl {
    char _pad[0x24];
    int *m_members;
    int *m_membersEnd;
    int *GetIndexedMember(int idx);
};

int *FamilyImpl::GetIndexedMember(int idx) {
    if (idx < 0 || idx >= (m_membersEnd - m_members))
        return 0;
    return m_members + idx;
}
