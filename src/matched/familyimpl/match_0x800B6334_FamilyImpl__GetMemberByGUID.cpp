// 0x800B6334 FamilyImpl::GetMemberByGUID(int) (52B)

struct FamilyImpl {
    char _pad[0x24];
    int *m_members;
    int *m_membersEnd;
    int *GetMemberByGUID(int guid);
};

int *FamilyImpl::GetMemberByGUID(int guid) {
    for (int *p = m_members; p != m_membersEnd; p++) {
        if (*p == guid)
            return p;
    }
    return 0;
}
