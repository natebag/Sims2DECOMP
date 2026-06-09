// 0x802D7024 FastAllocPool::Init(void*, int, int) (112 B)
//
// Carve a fixed-block free pool out of a caller-supplied buffer. The pool's
// alignment is the largest power of two that divides both the block size and the
// low 24 bits of the base address (isolated lowest set bit, x & -x). Each block
// gets a magic guard word at offset 0 and is pushed onto the singly-linked free
// list (next pointer at offset 4). The block-count bound is the just-stored
// member, reloaded every iteration because the per-block writes may alias it.

struct FastAllocPool {
    void* m_poolStart;   // 0x00
    void* m_freeList;    // 0x04
    int   m_poolBlocks;  // 0x08
    int   m_blockSize;   // 0x0C
    int   m_alignment;   // 0x10
    void* m_vtablePtr;   // 0x14
    void Init(void* mem, int blockSize, int count);
};

void FastAllocPool::Init(void* mem, int blockSize, int count)
{
    unsigned bits = (unsigned)blockSize | ((unsigned)mem & 0x00FFFFFF);
    m_alignment  = bits & -bits;
    m_freeList   = 0;
    m_poolStart  = mem;
    m_poolBlocks = count;
    m_blockSize  = blockSize;

    char* block = (char*)mem;
    for (unsigned i = 0; i < (unsigned)m_poolBlocks; i++) {
        if (block != 0) {
            *(unsigned*)block = 0x45455246;
            *(unsigned*)(block + 4) = (unsigned)m_freeList;
            m_freeList = block;
        }
        block += blockSize;
    }
}
