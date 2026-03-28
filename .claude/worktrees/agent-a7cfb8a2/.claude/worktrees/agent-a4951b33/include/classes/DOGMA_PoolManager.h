#ifndef DOGMA_POOLMANAGER_H
#define DOGMA_POOLMANAGER_H

#include "types.h"

// DOGMA_PoolManager - struct layout extracted from assembly analysis
// Estimated minimum size: 0x20 (32 bytes)
// 10 known fields (1 named), 23 methods

class DOGMA_PoolManager {
public:
    // Constructors / Destructors
    DOGMA_PoolManager(unsigned int, unsigned int, unsigned int, unsigned int, unsigned char, bool, unsigned char, bool, unsigned char, bool)  // 0x8070A16C
    ~DOGMA_PoolManager(void);  // 0x8070A3E8

    // Methods
    void Deallocate(void *, unsigned int);  // 0x8070AA78 (660B)
    void Allocate(unsigned int);  // 0x8070A73C (828B)
    /* ? */ GetTotalBytesUsed(void);  // 0x8070B0F0 (136B)
    /* ? */ GetFirstOutsideAllocation(void);  // 0x8070A544 (88B)
    void SizeVerifyAllocate(unsigned int);  // 0x8070A60C (112B)
    void SizeVerifyDeallocate(void *, unsigned int);  // 0x8070A67C (192B)
    /* ? */ GetNextOutsideAllocation(void *);  // 0x8070A59C (112B)
    void ToNextValidSize(unsigned int);  // 0x8070B078 (120B)
    bool HasFreeBlockBySize(unsigned int);  // 0x8070B338 (92B)
    void ConsumeFreeBlockBySize(unsigned int);  // 0x8070AD0C (468B)
    void AddFreeBlockBySize(void *, unsigned int);  // 0x8070AEE0 (408B)

    // ---- Field Layout (from assembly analysis) ----
    void** _vtable;  // 0x000 [R/W] - vtable pointer (AddFreeBlockBySize, Allocate, ConsumeFreeBlockBySize, ...)
    u32 m_field_004;  // 0x004 [R/W] (Allocate, DOGMA_PoolManager, Deallocate, ...)
    u32 m_field_008;  // 0x008 [R/W] (Allocate, DOGMA_PoolManager)
    u32 m_field_00C;  // 0x00C [R/W] (Allocate, DOGMA_PoolManager, Deallocate, ...)
    u8 m_field_010;  // 0x010 [R/W] (AddFreeBlockBySize, ConsumeFreeBlockBySize, DOGMA_PoolManager)
    u8 m_field_011;  // 0x011 [R/W] (AddFreeBlockBySize, DOGMA_PoolManager)
    u8 m_field_012;  // 0x012 [R/W] (AddFreeBlockBySize, ConsumeFreeBlockBySize, DOGMA_PoolManager)
    u8 _pad_013[1];  // 0x013
    u32 m_field_014;  // 0x014 [R/W] (Allocate, DOGMA_PoolManager, Deallocate, ...)
    u32 m_field_018;  // 0x018 [R/W] (Allocate, DOGMA_PoolManager, Deallocate)
    u32 m_field_01C;  // 0x01C [R/W] (AddFreeBlockBySize, ConsumeFreeBlockBySize, DOGMA_PoolManager)
};

#endif // DOGMA_POOLMANAGER_H
