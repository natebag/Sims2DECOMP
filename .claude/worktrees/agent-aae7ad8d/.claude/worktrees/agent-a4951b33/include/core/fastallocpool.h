// fastallocpool.h - FastAllocPool and ProtectedAllocPool class declarations
// From: base_ngc_release_dvd.lib(fastallocpool.obj)
//
// NOTE: The original SN Systems compiler places vtable pointers AFTER data fields.
// GCC places them before. To get matching field offsets, we omit virtual keywords
// and store the vtable pointer explicitly. This means destructors won't be virtual
// in the compiled output, but the field layout will match for all accessors.

#ifndef FASTALLOCPOOL_H
#define FASTALLOCPOOL_H

// Base alloc pool
// SN Systems layout:
//   0x00: m_poolStart
//   0x04: m_freeList
//   0x08: m_poolBlocks
//   0x0C: m_blockSize
//   0x10: m_alignment
//   0x14: vtable pointer (SN Systems places it here)
class ProtectedAllocPool {
public:
    void* m_poolStart;      // 0x00
    void* m_freeList;       // 0x04
    int m_poolBlocks;       // 0x08
    int m_blockSize;        // 0x0C
    int m_alignment;        // 0x10
    void* m_vtablePtr;      // 0x14

    // Non-virtual to avoid GCC vtable placement issues
    void Validate(void);
    void* Alloc(void);
    void Free(void* ptr);
    int BlockIsInPool(void* ptr) const;
    int GetAlignment(void) const;
    void* GetPoolStart(void) const;
    unsigned int GetPoolSize(void) const;
    int GetBlockSize(void) const;
    int GetPoolBlocks(void) const;
};

// FastAllocPool
// Same layout as ProtectedAllocPool
class FastAllocPool {
public:
    void* m_poolStart;      // 0x00
    void* m_freeList;       // 0x04
    int m_poolBlocks;       // 0x08
    int m_blockSize;        // 0x0C
    int m_alignment;        // 0x10
    void* m_vtablePtr;      // 0x14

    FastAllocPool();
    // NON_MATCHING: destructor uses virtual dispatch via m_vtablePtr in original
    ~FastAllocPool(void);

    void Init(void* pool, int blockSize, int numBlocks, int alignment);
    void Validate(void);
    void* Alloc(void);
    void Free(void* ptr);
    int BlockIsInPool(void* ptr) const;
    int GetAlignment(void) const;
    void* GetPoolStart(void) const;
    unsigned int GetPoolSize(void) const;
    int GetBlockSize(void) const;
    int GetPoolBlocks(void) const;
};

#endif // FASTALLOCPOOL_H
