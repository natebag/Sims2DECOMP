/* CareersImpl::GetJobGrade(int) at 0x800B179C (52B) */

struct CareersImpl_JG {
    char pad[12];
    int** m_jobGrades;
    char pad2[12];
    int m_defaultGrade;
    int* GetJobGrade(int idx);
};

int* CareersImpl_JG::GetJobGrade(int idx) {
    int* data = *m_jobGrades;
    int count = 0;
    if (data) count = data[-1];
    if (idx >= count) return &m_defaultGrade;
    return data + idx;
}
