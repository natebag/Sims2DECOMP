struct EResourceLoaderImpl {
    char _pad[0x378];
    char m_sub;
    void CollapseDelRef(void* a, unsigned int b);
};

void Impl_80310730(void*, void*, unsigned int);

void EResourceLoaderImpl::CollapseDelRef(void* a, unsigned int b) {
    Impl_80310730(&m_sub, a, b);
}
