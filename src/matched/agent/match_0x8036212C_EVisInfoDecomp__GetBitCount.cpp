struct EVisInfoDecomp {
    char _p[0x08];
    int m_val;
    int GetBitCount();
};
int EVisInfoDecomp::GetBitCount() { return m_val; }
