struct EResourceMap {
    char _pad[0x08];
    int m_maxEntries;
    int GetMaxEntries();
};
int EResourceMap::GetMaxEntries() { return m_maxEntries; }
