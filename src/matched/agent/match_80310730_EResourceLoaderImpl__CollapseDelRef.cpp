class SubObj {
public:
    void CollapseDelRef(void*, unsigned int);
};

class EResourceLoaderImpl {
    char pad[888];
    SubObj m_sub;
public:
    void CollapseDelRef(void* a, unsigned int b);
};

void EResourceLoaderImpl::CollapseDelRef(void* a, unsigned int b) {
    m_sub.CollapseDelRef(a, b);
}
