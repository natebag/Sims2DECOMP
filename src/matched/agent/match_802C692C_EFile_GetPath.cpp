struct EFile_GP {
    char pad[0x1C];
    char* m_path;
    char* GetPath() const;
};

char* EFile_GP::GetPath() const {
    return m_path;
}
