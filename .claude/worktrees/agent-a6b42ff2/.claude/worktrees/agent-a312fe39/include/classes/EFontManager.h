#ifndef EFONTMANAGER_H
#define EFONTMANAGER_H

#include "types.h"

// EFontManager - struct layout extracted from assembly analysis
// Estimated minimum size: 0xC (12 bytes)
// 2 known fields (0 named), 9 methods

class EFontManager {
public:
    // Constructors / Destructors
    EFontManager(void)  // 0x808894BC
    ~EFontManager(void);  // 0x80889508

    // Methods
    void AddRef(unsigned int, EFile *, int);  // 0x808895BC (92B)
    void AllocateAndLoadResource(EFile *, unsigned int, unsigned int);  // 0x808893B8 (260B)
    void AddRef(char *, EFile *, int);  // 0x80889618 (92B)

    // ---- Field Layout (from assembly analysis) ----
    u32 m_field_000;  // 0x000 [R] (AllocateAndLoadResource)
    u8 _pad_004[4];  // 0x004
    u32 m_field_008;  // 0x008 [W] (AllocateAndLoadResource)
};

#endif // EFONTMANAGER_H
