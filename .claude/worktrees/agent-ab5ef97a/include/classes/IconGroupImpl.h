#ifndef ICONGROUPIMPL_H
#define ICONGROUPIMPL_H

#include "types.h"

// IconGroupImpl - struct layout extracted from assembly analysis
// Estimated minimum size: 0x10 (16 bytes)
// 4 known fields (4 named), 16 methods

class IconGroupImpl {
public:
    // Constructors / Destructors
    IconGroupImpl(void)  // 0x8024FA1C
    ~IconGroupImpl(void);  // 0x8024FB20

    // Methods
    void Init(int);  // 0x8024FA88 (152B)
    /* ? */ GetSpriteID(int);  // 0x8024FB7C (180B)
    /* ? */ GetLabel(StringBuffer &);  // 0x8024FC30 (36B)
    void LoadStrings(void);  // 0x8024FC54 (32B)
    /* ? */ GetIconLabel(int, StringBuffer &);  // 0x8024FC74 (236B)
    void CountIconLabels(void);  // 0x8024FD60 (168B)

    // ---- Field Layout (from assembly analysis) ----
    void** _vtable;  // 0x000 [W] - vtable pointer (~IconGroupImpl)
    u16 m_spriteID;  // 0x004 [R/W] (GetSpriteID, Init)
    u8 _pad_006[2];  // 0x006
    u32 m_iconLabel;  // 0x008 [R] (CountIconLabels, GetIconLabel, ~IconGroupImpl)
    u32 m_spriteID_00C;  // 0x00C [R/W] (GetSpriteID, Init)
};

#endif // ICONGROUPIMPL_H
