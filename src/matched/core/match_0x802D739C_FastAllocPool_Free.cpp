// FastAllocPool::Free(void*) @ 0x802D739C (36B)
// FLAGS: -fno-schedule-insns

struct FastAllocPool {
    char _0[4];
    void* m_freeHead;
};

void FastAllocPool_Free(FastAllocPool* pool, void* ptr) {
    if (ptr == 0) return;
    *(int*)ptr = 0x45455246;
    ((void**)ptr)[1] = pool->m_freeHead;
    pool->m_freeHead = ptr;
}
