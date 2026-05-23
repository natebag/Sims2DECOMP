// 0x802BC098 (88B) AptValueVector::~AptValueVector(void)
// Variant L: SI deleting-dtor, DOGMA_PoolManager_Deallocate for both data buffer and self.

extern void* g_dogmaPool;

void DOGMA_PoolManager_Deallocate(void* mgr, void* p, unsigned int size);

struct AptValueVector {
    unsigned int m_count;
    int m_field_4;
    void* m_data;
    void dtor(int flag);
};

void AptValueVector::dtor(int flag) {
    DOGMA_PoolManager_Deallocate(g_dogmaPool, m_data, m_count * 4);
    if (flag & 1) {
        DOGMA_PoolManager_Deallocate(g_dogmaPool, this, 12);
    }
}
