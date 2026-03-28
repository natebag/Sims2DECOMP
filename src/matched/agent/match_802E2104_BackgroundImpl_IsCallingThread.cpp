struct Inner_ICT {
    int IsCallingThread();
};
struct BGImpl_ICT {
    char pad[0x08];
    Inner_ICT m_thread;
    int IsCallingThread();
};
int BGImpl_ICT::IsCallingThread() {
    return m_thread.IsCallingThread();
}
