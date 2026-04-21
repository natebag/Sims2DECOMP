// 0x802C7328 EFixedPool::~EFixedPool (72B)
// dtor: bl MainHeap(); bl heap->Free(this->m_pool); if (free) delete this;

struct EAHeap {
    void Free(void* p);
};

extern EAHeap* MainHeap();

struct EFixedPool {
    void* m_unused;
    void* m_pool;
    ~EFixedPool();
};

EFixedPool::~EFixedPool() {
    MainHeap()->Free(m_pool);
}
