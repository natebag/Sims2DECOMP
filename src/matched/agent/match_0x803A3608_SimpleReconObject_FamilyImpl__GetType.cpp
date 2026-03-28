struct SimpleReconObject_FamilyImpl {
    char _p[0x08];
    int m_type;
    int GetType();
};
int SimpleReconObject_FamilyImpl::GetType() { return m_type; }
