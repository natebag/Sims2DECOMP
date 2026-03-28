#ifndef ANIMTABLEIMPL_H
#define ANIMTABLEIMPL_H

#include "types.h"

// AnimTableImpl - struct layout extracted from assembly analysis
// Estimated minimum size: 0xC (12 bytes)
// 2 known fields (0 named), 14 methods

class AnimTableImpl {
public:
    // Constructors / Destructors
    AnimTableImpl(void)  // 0x80210014
    ~AnimTableImpl(void);  // 0x80210068

    // Methods
    void Load(unsigned int, short);  // 0x802100B4 (376B)
    /* ? */ GetEntry(int);  // 0x8021022C (248B)
    /* ? */ GetID(void);  // 0x80210F60 (52B)
    /* ? */ GetEntryName(int);  // 0x80211020 (164B)
    void CountEntries(void);  // 0x80210FDC (68B)

    // ---- Field Layout (from assembly analysis) ----
    u8 _pad_000[4];  // 0x000
    u32 m_field_004;  // 0x004 [W] (Load)
    u32 m_field_008;  // 0x008 [R] (Load)
};

#endif // ANIMTABLEIMPL_H
