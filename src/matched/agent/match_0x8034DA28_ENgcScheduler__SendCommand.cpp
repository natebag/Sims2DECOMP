struct ENgcScheduler {
    char _pad[0x348];
    char m_queue;
    void SendCommand(void*);
};

void Impl_8034DA28(void*, void*, int);

void ENgcScheduler::SendCommand(void* cmd) {
    Impl_8034DA28(&m_queue, cmd, 1);
}
