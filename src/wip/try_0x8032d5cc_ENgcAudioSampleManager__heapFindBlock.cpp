// 0x8032d5cc ENgcAudioSampleManager::heapFindBlock(unsigned int) const (52B)
struct ARAMBlock {
    char _pad[4];
    ARAMBlock* next;
    char _pad2[8];
    unsigned int addr;
};
struct ENgcAudioSampleManager {
    char _pad[0xd20];
    ARAMBlock* m_heap;
    ARAMBlock* heapFindBlock(unsigned int addr) const;
};
ARAMBlock* ENgcAudioSampleManager::heapFindBlock(unsigned int addr) const {
    ARAMBlock* block = m_heap;
    if (!block) return 0;
    while (true) {
        if (block->addr == addr) return block;
        block = block->next;
        if (!block) return 0;
    }
}
