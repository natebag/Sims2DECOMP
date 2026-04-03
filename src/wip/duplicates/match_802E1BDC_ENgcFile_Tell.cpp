struct ENgcFile_T {
    char pad[0x68];
    int m_pos;
    int Tell() const;
};
int ENgcFile_T::Tell() const {
    return m_pos;
}
