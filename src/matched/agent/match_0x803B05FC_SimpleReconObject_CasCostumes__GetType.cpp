struct SimpleReconObject_CasCostumes {
    char _p[0x08];
    int m_type;
    int GetType();
};
int SimpleReconObject_CasCostumes::GetType() { return m_type; }
