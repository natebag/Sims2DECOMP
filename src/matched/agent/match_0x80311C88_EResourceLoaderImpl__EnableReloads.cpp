struct EResourceLoaderImpl {
    char _pad[0x3e0];
    int m_enableReloads;
    void EnableReloads(int val);
};
void EResourceLoaderImpl::EnableReloads(int val) { m_enableReloads = val; }
