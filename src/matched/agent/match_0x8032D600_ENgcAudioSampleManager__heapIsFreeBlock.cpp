// 0x8032d600 ENgcAudioSampleManager::heapIsFreeBlock(ARAMBlock*) const (52B)
// DOL: if next!=0 || prev!=0 || freeHead==block → return 1, else 0
// Uses separate bne branches all targeting same li r9,1 block
// ASMPROC_swap_operands: match="cmpw 0,0,4" pos=1,2
struct ARAMBlock {
    char _pad[8];
    ARAMBlock* m_prev;  // +8
    ARAMBlock* m_next;  // +0xc
};
struct ENgcAudioSampleManager {
    char _pad[0xd24];
    ARAMBlock* m_freeHead;  // +0xd24
    int heapIsFreeBlock(ARAMBlock* block) const;
};
int ENgcAudioSampleManager::heapIsFreeBlock(ARAMBlock* block) const {
    int result = 0;
    if (block->m_next != 0 || block->m_prev != 0 || m_freeHead == block)
        result = 1;
    return result;
}
