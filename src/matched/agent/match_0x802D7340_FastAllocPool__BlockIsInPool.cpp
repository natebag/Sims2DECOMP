// 0x802D7340 FastAllocPool::BlockIsInPool(void *) const (52B)

class FastAllocPool {
public:
    void* m_base;
    char _pad4[4];
    unsigned int m_blockCount;
    unsigned int m_blockSize;

    int BlockIsInPool(void* block) const;
};

int FastAllocPool::BlockIsInPool(void* block) const {
    int result = 0;
    if ((unsigned int)block >= (unsigned int)m_base) {
        unsigned int total = m_blockSize * m_blockCount;
        char* end = (char*)m_base + total;
        if ((unsigned int)block < (unsigned int)end) {
            result = 1;
        }
    }
    return result;
}
