struct SimpleReconObject_CasGenetics {
    char _p[0x08];
    int m_type;
    int GetType();
};
int SimpleReconObject_CasGenetics::GetType() { return m_type; }
