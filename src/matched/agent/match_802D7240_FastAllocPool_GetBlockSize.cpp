struct FastAllocPool_GBS {
    char pad[0x0C];
    int m_blockSize;
    int GetBlockSize() const;
};

int FastAllocPool_GBS::GetBlockSize() const {
    return m_blockSize;
}
