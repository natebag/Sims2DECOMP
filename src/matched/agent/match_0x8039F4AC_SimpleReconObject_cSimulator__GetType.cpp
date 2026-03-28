struct SimpleReconObject_cSimulator {
    char _p[0x08];
    int m_type;
    int GetType();
};
int SimpleReconObject_cSimulator::GetType() { return m_type; }
