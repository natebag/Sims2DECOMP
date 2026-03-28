struct EResourceManager {
    char _pad[0x58];
    char m_sub;
    void GetUnreferencedResourceCount();
};

void Impl_80327630(void*);

void EResourceManager::GetUnreferencedResourceCount() {
    Impl_80327630(&m_sub);
}
