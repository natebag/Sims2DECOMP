// 0x8012C7EC cXPersonImpl::GetSAnimator (8B)

struct cXPerson_GSA {
    char pad[0x3F4];
    int m_val;
    int GetSAnimator();
};

int cXPerson_GSA::GetSAnimator() {
    return m_val;
}
