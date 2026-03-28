struct EResourceManager {
    char _pad[0xD08];
    char m_sub;
    void RefreshResources();
};

void Impl_80326DFC(void*);

void EResourceManager::RefreshResources() {
    Impl_80326DFC(&m_sub);
}
