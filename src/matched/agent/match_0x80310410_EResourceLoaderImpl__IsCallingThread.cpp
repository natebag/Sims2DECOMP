struct EResourceLoaderImpl {
    char _pad[0x8];
    char m_sub;
    void IsCallingThread();
};

void Impl_80310410(void*);

void EResourceLoaderImpl::IsCallingThread() {
    Impl_80310410(&m_sub);
}
