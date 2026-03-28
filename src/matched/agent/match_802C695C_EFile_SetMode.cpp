struct EFile_SM {
    char pad[0x08];
    int m_ioMode;
    void SetMode(int mode);
};

void EFile_SM::SetMode(int mode) {
    m_ioMode = mode;
}
