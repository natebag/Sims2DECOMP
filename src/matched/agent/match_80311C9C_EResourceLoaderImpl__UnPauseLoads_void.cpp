class SomeEvent {
public:
    void Signal();
};

class EResourceLoaderImpl {
    char pad[1000];
    int m_paused;
    SomeEvent m_event;
public:
    void UnPauseLoads();
};

void EResourceLoaderImpl::UnPauseLoads() {
    m_paused = 0;
    m_event.Signal();
}
