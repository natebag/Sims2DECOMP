struct EResPrefetchFile {
    char _pad[0x2c];
    int m_resMan;
    int GetResMan();
};
int EResPrefetchFile::GetResMan() { return m_resMan; }
