// 0x802D7230 (16 bytes) - FastAllocPool::GetPoolSize(void) const
// lwz r0,8(r3); lwz r3,12(r3); divwu r3,r3,r0; blr

struct FastAllocPool_GPS {
    char pad[8];
    unsigned int m_elemSize;
    unsigned int m_totalBytes;

    unsigned int GetPoolSize() const;
};

unsigned int FastAllocPool_GPS::GetPoolSize() const {
    return m_totalBytes * m_elemSize;
}
