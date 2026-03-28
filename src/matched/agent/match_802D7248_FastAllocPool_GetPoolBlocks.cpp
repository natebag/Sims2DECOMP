struct FastAllocPool_GPB {
    char pad[0x08];
    int m_poolBlocks;
    int GetPoolBlocks() const;
};

int FastAllocPool_GPB::GetPoolBlocks() const {
    return m_poolBlocks;
}
