struct EResourceMap {
    char _pad[0x04];
    int m_numEntries;
    int GetNumEntries();
};
int EResourceMap::GetNumEntries() { return m_numEntries; }
