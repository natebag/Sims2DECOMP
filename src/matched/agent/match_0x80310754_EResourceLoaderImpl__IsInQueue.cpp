struct EResourceLoaderImpl {
    char _pad[0x378];
    char m_sub;
    void IsInQueue(void* a, unsigned int b);
};

void Impl_80310754(void*, void*, unsigned int);

void EResourceLoaderImpl::IsInQueue(void* a, unsigned int b) {
    Impl_80310754(&m_sub, a, b);
}
