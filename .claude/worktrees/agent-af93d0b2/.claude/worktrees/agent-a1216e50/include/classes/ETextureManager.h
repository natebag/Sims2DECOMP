#ifndef ETEXTUREMANAGER_H
#define ETEXTUREMANAGER_H

#include "types.h"

// ETextureManager - struct layout extracted from assembly analysis
// Estimated minimum size: 0xC (12 bytes)
// 2 known fields (0 named), 13 methods

class ETextureManager {
public:
    // Constructors / Destructors
    ETextureManager(void)  // 0x8089AB8C
    ~ETextureManager(void);  // 0x8089ABD8

    // Methods
    void AddRef(unsigned int, EFile *, int);  // 0x8089AC8C (92B)
    /* ? */ GetHeap(void);  // 0x8089AA48 (64B)
    void AllocateAndLoadResource(EFile *, unsigned int, unsigned int);  // 0x8089AA88 (260B)
    bool CanCache(EResource *);  // 0x8089AD44 (44B)
    void AddRef(char *, EFile *, int);  // 0x8089ACE8 (92B)

    // ---- Field Layout (from assembly analysis) ----
    u32 m_field_000;  // 0x000 [R] (AllocateAndLoadResource)
    u8 _pad_004[4];  // 0x004
    u32 m_field_008;  // 0x008 [W] (AllocateAndLoadResource)
};

#endif // ETEXTUREMANAGER_H
