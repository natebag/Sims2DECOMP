#ifndef ECHARACTERMANAGER_H
#define ECHARACTERMANAGER_H

#include "types.h"

// ECharacterManager - struct layout extracted from assembly analysis
// Estimated minimum size: 0xC (12 bytes)
// 2 known fields (0 named), 11 methods

class ECharacterManager {
public:
    // Constructors / Destructors
    ECharacterManager(void)  // 0x80884390
    ~ECharacterManager(void);  // 0x808843DC

    // Methods
    void AddRef(unsigned int, EFile *, int);  // 0x80884684 (92B)
    void AllocateAndLoadResource(EFile *, unsigned int, unsigned int);  // 0x80883B48 (260B)
    bool CanCache(EResource *);  // 0x8088473C (44B)
    void AddRef(char *, EFile *, int);  // 0x808846E0 (92B)

    // ---- Field Layout (from assembly analysis) ----
    u32 m_field_000;  // 0x000 [R] (AllocateAndLoadResource)
    u8 _pad_004[4];  // 0x004
    u32 m_field_008;  // 0x008 [W] (AllocateAndLoadResource)
};

#endif // ECHARACTERMANAGER_H
