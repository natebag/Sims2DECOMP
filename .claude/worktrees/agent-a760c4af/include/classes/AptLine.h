#ifndef APTLINE_H
#define APTLINE_H

#include "types.h"

// AptLine - struct layout extracted from assembly analysis
// Estimated minimum size: 0x30 (48 bytes)
// 4 known fields (1 named), 9 methods

class AptLine {
public:
    // Constructors / Destructors
    AptLine(void)  // 0x80022C88
    ~AptLine(void);  // 0x80022F30

    // Methods
    void AddWord(AptWord *);  // 0x8001E348 (124B)
    void UnlinkWord(AptWord *);  // 0x8001E3C4 (192B)
    void Draw(ERC *, EMat4 *, EVec4 *, EVec4 *);  // 0x8001E484 (192B)

    // ---- Field Layout (from assembly analysis) ----
    void** _vtable;  // 0x000 [R/W] - vtable pointer (UnlinkWord, ~AptLine)
    u32 m_field_004;  // 0x004 [R/W] (Draw, UnlinkWord, ~AptLine)
    u8 _pad_008[4];  // 0x008
    u32 m_field_00C;  // 0x00C [W] (~AptLine)
    u8 _pad_010[0x1C];  // 0x010
    u32 m_field_02C;  // 0x02C [R] (~AptLine)
};

#endif // APTLINE_H
