struct EFile_GE {
    char pad[0x24];
    char m_ext;
    char* GetExt() const;
};

char* EFile_GE::GetExt() const {
    return (char*)&m_ext;
}
