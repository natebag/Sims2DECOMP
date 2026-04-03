class SubObj {
public:
    void GetQueueStats(int&, int&, int&, int&);
};

class EResourceLoaderImpl {
    char pad[888];
    SubObj m_sub;
public:
    void GetQueueStats(int& a, int& b, int& c, int& d);
};

void EResourceLoaderImpl::GetQueueStats(int& a, int& b, int& c, int& d) {
    m_sub.GetQueueStats(a, b, c, d);
}
