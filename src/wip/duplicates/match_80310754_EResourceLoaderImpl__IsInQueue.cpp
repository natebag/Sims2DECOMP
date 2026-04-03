class SubObj {
public:
    void IsInQueue(void*, unsigned int);
};

class EResourceLoaderImpl {
    char pad[888];
    SubObj m_sub;
public:
    void IsInQueue(void* a, unsigned int b);
};

void EResourceLoaderImpl::IsInQueue(void* a, unsigned int b) {
    m_sub.IsInQueue(a, b);
}
