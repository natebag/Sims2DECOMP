struct EResourceLoaderImpl {
    char _pad[0x378];
    char m_queue;
    void sendCommand(void*);
};

void Impl_803104B4(void*, void*, int);

void EResourceLoaderImpl::sendCommand(void* cmd) {
    Impl_803104B4(&m_queue, cmd, 1);
}
