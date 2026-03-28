struct EDL {
    char _p[0x48];
    int m_start;
    int GetStart();
};
int EDL::GetStart() { return m_start; }
