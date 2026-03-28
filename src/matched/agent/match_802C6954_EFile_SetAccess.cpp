struct EFile_SA {
    char pad[0x0C];
    int m_accessMode;
    void SetAccess(int mode);
};

void EFile_SA::SetAccess(int mode) {
    m_accessMode = mode;
}
