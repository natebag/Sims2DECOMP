#ifndef ESHADERMANAGER_H
#define ESHADERMANAGER_H

#include "types.h"

// EShaderManager - struct layout extracted from assembly analysis
// Estimated minimum size: 0xC (12 bytes)
// 2 known fields (0 named), 13 methods

class EShaderManager {
public:
    // Constructors / Destructors
    EShaderManager(void)  // 0x80899F04
    ~EShaderManager(void);  // 0x80899F50

    // Methods
    void AddRef(unsigned int, EFile *, int);  // 0x8089A004 (92B)
    void AddRef(char *, EFile *, int);  // 0x8089A060 (92B)
    /* ? */ GetHeap(void);  // 0x80899DC0 (64B)
    void AllocateAndLoadResource(EFile *, unsigned int, unsigned int);  // 0x80899E00 (260B)
    bool CanCache(EResource *);  // 0x8089A0BC (44B)

    // ---- Field Layout (from assembly analysis) ----
    u32 m_field_000;  // 0x000 [R] (AllocateAndLoadResource)
    u8 _pad_004[4];  // 0x004
    u32 m_field_008;  // 0x008 [W] (AllocateAndLoadResource)
};

#endif // ESHADERMANAGER_H
