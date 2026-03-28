struct SimpleReconObject_IFFResMap {
    char _p[0x08];
    int m_type;
    int GetType();
};
int SimpleReconObject_IFFResMap::GetType() { return m_type; }
