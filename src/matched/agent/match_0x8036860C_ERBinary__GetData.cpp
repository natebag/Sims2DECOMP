struct ERBinary {
    char _p[0x14];
    int m_data;
    int GetData();
};
int ERBinary::GetData() { return m_data; }
