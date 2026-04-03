struct EFixedPool_S {
    void* m_pool;
    int m_count;
    EFixedPool_S();
};

EFixedPool_S::EFixedPool_S() {
    m_pool = 0;
    m_count = 0;
}
