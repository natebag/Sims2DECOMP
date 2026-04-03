struct EResourceMap {
    char _pad[0x10];
    int m_maxUsed;
    int GetMaxUsed();
};
int EResourceMap::GetMaxUsed() { return m_maxUsed; }
