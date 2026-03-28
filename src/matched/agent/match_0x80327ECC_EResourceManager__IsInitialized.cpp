struct EResourceManager {
    char _pad[0x48];
    int m_initialized;
    int IsInitialized();
};
int EResourceManager::IsInitialized() { return m_initialized; }
