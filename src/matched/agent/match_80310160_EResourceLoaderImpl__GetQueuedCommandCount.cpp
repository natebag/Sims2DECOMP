class SubObj {
public:
    int GetQueuedCommandCount();
};

class EResourceLoaderImpl {
    char pad[888];
    SubObj m_sub;
public:
    int GetQueuedCommandCount();
};

int EResourceLoaderImpl::GetQueuedCommandCount() {
    return m_sub.GetQueuedCommandCount();
}
