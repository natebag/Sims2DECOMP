struct ERBinary {
    char _p[0x18];
    int m_dataSize;
    int GetDataSize();
};
int ERBinary::GetDataSize() { return m_dataSize; }
