// 0x802D6F7C FastAllocPool::FastAllocPool(char*, void*, int, int) (116 B)
// FLAGS:
//
// FastAllocPool constructor: installs the vtable (SN-style at +0x14, after the
// 5 data words), clears all pool bookkeeping, then — only if it was handed real
// backing memory, a non-zero block size and a non-zero count — initializes the
// pool via Init. The leading char* (debug name) is unused. vptr-at-+0x14 comes
// from declaring the data members before the virtuals (SN ABI).

struct FastAllocPool {
    void* m_poolStart;   // 0x00
    void* m_freeList;    // 0x04
    int   m_poolBlocks;  // 0x08
    int   m_blockSize;   // 0x0C
    int   m_alignment;   // 0x10
    /* vptr @ 0x14 */
    FastAllocPool(char* name, void* mem, int blockSize, int count);
    virtual ~FastAllocPool();
    virtual void  Validate();
    virtual void* Alloc();
    virtual void  Free(void* p);
    void Init(void* mem, int blockSize, int count);
};

FastAllocPool::FastAllocPool(char* name, void* mem, int blockSize, int count)
{
    m_poolStart  = 0;
    m_freeList   = 0;
    m_poolBlocks = 0;
    m_blockSize  = 0;
    m_alignment  = 0;
    if (mem != 0 && blockSize != 0 && count != 0)
        Init(mem, blockSize, count);
}
