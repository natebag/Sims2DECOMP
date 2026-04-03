class SubObj {
public:
    int IsCallingThread();
};

class EResourceLoaderImpl {
    char pad[8];
    SubObj m_sub;
public:
    int IsCallingThread();
};

int EResourceLoaderImpl::IsCallingThread() {
    return m_sub.IsCallingThread();
}
