struct SimpleReconObject_ReconStreamVector_SlotDescriptor {
    char _p[0x08];
    int m_type;
    int GetType();
};
int SimpleReconObject_ReconStreamVector_SlotDescriptor::GetType() { return m_type; }
