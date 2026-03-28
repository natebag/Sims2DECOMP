struct SimpleReconObject_NeighborhoodImpl {
    char _p[0x08];
    int m_type;
    int GetType();
};
int SimpleReconObject_NeighborhoodImpl::GetType() { return m_type; }
