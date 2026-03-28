struct EResourceLoaderImpl {
    char _pad[0x3e8];
    int m_loadsPaused;
    int AreLoadsPaused();
};
int EResourceLoaderImpl::AreLoadsPaused() { return m_loadsPaused; }
