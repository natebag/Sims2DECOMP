#ifndef EDL_H
#define EDL_H

#include "types.h"

// EDL - struct layout extracted from assembly analysis
// Estimated minimum size: 0x68 (104 bytes)
// 10 known fields (2 named), 20 methods

class EDL {
public:
    // Constructors / Destructors
    EDL(int)  // 0x8090BBC8
    ~EDL(void);  // 0x8090BC7C

    // Methods
    void Validate(void);  // 0x8090BD10 (284B)
    void Alloc(unsigned int, int);  // 0x8090C1AC (84B)
    void AllocExternal(void *, int);  // 0x8090C200 (68B)
    void AllocFlushable(unsigned int, int);  // 0x8090C244 (88B)
    void AllocFlushableExternal(void *, int);  // 0x8090C29C (72B)
    /* ? */ GetStart(void);  // 0x8090C180 (44B)
    /* ? */ GetVertCount(void);  // 0x8090C2E4 (44B)
    /* ? */ GetAverageStripLength(void);  // 0x8090C310 (124B)

    // ---- Field Layout (from assembly analysis) ----
    u8 _pad_000[0x18];  // 0x000
    u32 m_field_018;  // 0x018 [R] (operator new)
    u8 _pad_01C[0x14];  // 0x01C
    u32 m_field_030;  // 0x030 [R/W] (EDL, Validate)
    u8 _pad_034[8];  // 0x034
    u32 m_field_03C;  // 0x03C [R/W] (EDL, Validate)
    u8 _pad_040[8];  // 0x040
    u32 m_field_048;  // 0x048 [W] (EDL)
    u32 m_field_04C;  // 0x04C [W] (EDL)
    u32 m_field_050;  // 0x050 [W] (EDL)
    u32 m_field_054;  // 0x054 [W] (EDL)
    u32 m_averageStripLength;  // 0x058 [R/W] (EDL, GetAverageStripLength)
    u32 m_averageStripLength_05C;  // 0x05C [R/W] (EDL, GetAverageStripLength)
    u8 _pad_060[4];  // 0x060
    u32 m_field_064;  // 0x064 [W] (EDL, ~EDL)
};

#endif // EDL_H
