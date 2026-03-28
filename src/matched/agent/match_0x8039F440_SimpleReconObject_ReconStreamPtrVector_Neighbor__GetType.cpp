struct SimpleReconObject_ReconStreamPtrVector_Neighbor {
    char _p[0x08];
    int m_type;
    int GetType();
};
int SimpleReconObject_ReconStreamPtrVector_Neighbor::GetType() { return m_type; }
