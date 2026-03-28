struct ENgcSNFile_T {
    char pad[0x30];
    int m_pos;
    int Tell() const;
};

int ENgcSNFile_T::Tell() const {
    return m_pos;
}
