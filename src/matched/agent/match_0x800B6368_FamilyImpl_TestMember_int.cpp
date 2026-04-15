// 0x800B6368 (60B) FamilyImpl::TestMember(int) const

struct FamilyImpl {
    char pad[36];
    int* m_start;
    int* m_end;

    bool TestMember(int id) const;
};

bool FamilyImpl::TestMember(int id) const {
    for (int* cur = m_start; cur != m_end; cur++) {
        if (*cur == id) return 1;
    }
    return 0;
}
