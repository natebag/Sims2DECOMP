struct EResourceLoaderImpl {
    char _pad[0x378];
    char m_sub;
    void GetQueuedCommandCount();
};

void Impl_80310160(void*);

void EResourceLoaderImpl::GetQueuedCommandCount() {
    Impl_80310160(&m_sub);
}
