struct EDL {
    char _p[0x54];
    int m_val;
    int GetVertCount();
};
int EDL::GetVertCount() { return m_val; }
