class ENgcFile {
public:
    char m_pad[104];
    int m_pos;
    int Tell() const;
};
int ENgcFile::Tell() const { return m_pos; }
