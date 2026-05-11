/* FastAllocPool::Alloc(void) - 0x802D7374 - 40 bytes */

struct FastAllocPool {
    void* m_poolStart;
    void* m_freeHead;
    int m_poolBlocks;
    int m_blockSize;
};

void* FastAllocPool_Alloc(FastAllocPool* pool) {
    void* result = 0;
    result = pool->m_freeHead;
    if (result != 0) {
        pool->m_freeHead = ((void**)result)[1];
        *(unsigned int*)result = 0x44455355;
    }
    return result;
}
