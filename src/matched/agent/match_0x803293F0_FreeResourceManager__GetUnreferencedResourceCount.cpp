struct FreeResourceManager {
    char _pad[0xca0];
    int m_count;
    int GetUnreferencedResourceCount();
};
int FreeResourceManager::GetUnreferencedResourceCount() { return m_count; }
