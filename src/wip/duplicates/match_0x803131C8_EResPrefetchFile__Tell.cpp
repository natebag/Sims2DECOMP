struct EResPrefetchFile {
    char _pad[0x40];
    int m_pos;
    int Tell() const;
};
int EResPrefetchFile::Tell() const { return m_pos; }
