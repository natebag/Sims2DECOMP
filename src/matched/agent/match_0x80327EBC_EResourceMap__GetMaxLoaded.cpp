struct EResourceMap {
    char _pad[0x0c];
    int m_maxLoaded;
    int GetMaxLoaded();
};
int EResourceMap::GetMaxLoaded() { return m_maxLoaded; }
