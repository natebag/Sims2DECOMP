struct SimpleReconObject_HouseImpl {
    char _p[0x08];
    int m_type;
    int GetType();
};
int SimpleReconObject_HouseImpl::GetType() { return m_type; }
