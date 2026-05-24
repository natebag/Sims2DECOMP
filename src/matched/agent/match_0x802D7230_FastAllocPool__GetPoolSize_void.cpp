// 0x802D7230 FastAllocPool::GetPoolSize(void) (16B)
// lwz r0,0x8(r3); lwz r3,0xc(r3); mullw r3,r3,r0; blr — no flags, scheduler reorders loads
struct FastAllocPool {
    char pad[8];
    int m_blockSize;   // offset 0x8
    int m_blockCount;  // offset 0xc
    int GetPoolSize() const;
};
int FastAllocPool::GetPoolSize() const {
    return m_blockCount * m_blockSize;
}
