// 0x8012C714 cXPersonImpl::GetPendingAction (24B) const

struct cXPerson_GPA {
    char pad[0x534];
    int m_val;
    int GetPendingAction() const;
};

int cXPerson_GPA::GetPendingAction() const {
    int v = m_val;
    int result = 0;
    if (v != 0) result = 1;
    return result;
}
