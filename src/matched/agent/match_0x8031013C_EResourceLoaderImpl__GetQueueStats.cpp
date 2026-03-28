struct EResourceLoaderImpl {
    char _pad[0x378];
    char m_sub;
    void GetQueueStats(int& a, int& b, int& c, int& d);
};

void Impl_8031013C(void*, int&, int&, int&, int&);

void EResourceLoaderImpl::GetQueueStats(int& a, int& b, int& c, int& d) {
    Impl_8031013C(&m_sub, a, b, c, d);
}
