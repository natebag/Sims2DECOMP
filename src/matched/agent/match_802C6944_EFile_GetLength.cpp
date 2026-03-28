struct EFile_GL {
    char pad[0x14];
    int m_length;
    int GetLength() const;
};

int EFile_GL::GetLength() const {
    return m_length;
}
