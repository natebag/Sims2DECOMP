struct EFile_GIM {
    char pad[0x08];
    int m_ioMode;
    int GetIOMode() const;
};

int EFile_GIM::GetIOMode() const {
    return m_ioMode;
}
