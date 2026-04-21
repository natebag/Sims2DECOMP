// 0x80134BF0 (84B) RelMatrixImpl::GetArraySize(int)

struct MemberArray {
    void* m_start;
    void* m_end;
};

struct RelMatrixImpl {
    char pad[4];
    MemberArray** m_rowStart;
    MemberArray** m_rowEnd;

    MemberArray** FindArray(int row);
    int GetArraySize(int row);
};

int RelMatrixImpl::GetArraySize(int row) {
    MemberArray** it = FindArray(row);
    if (it != m_rowEnd) {
        MemberArray* m = *it;
        return (int*)m->m_end - (int*)m->m_start;
    }
    return 0;
}
