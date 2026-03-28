#ifndef ETWEAK_H
#define ETWEAK_H

#include "types.h"

// ETweak - struct layout extracted from assembly analysis
// Estimated minimum size: 0x28 (40 bytes)
// 8 known fields (0 named), 18 methods

class ETweak {
public:
    // Constructors / Destructors
    ETweak(void)  // 0x80820AC4
    ~ETweak(void);  // 0x80820B44

    // Methods
    void Update(void);  // 0x80820BD0 (196B)
    void Read(void);  // 0x80820C94 (792B)
    void FileName(char *);  // 0x80820FAC (180B)
    void AddVal(void *, char *, int);  // 0x80821060 (468B)
    void AddVal(EString *, char *, int);  // 0x80821234 (468B)
    void RemoveVal(void *);  // 0x80821408 (220B)
    void RemoveAll(void);  // 0x808214E4 (60B)

    // ---- Field Layout (from assembly analysis) ----
    f32 m_field_000;  // 0x000 [R/W] (AddVal, ETweak, Read, ...)
    f32 m_field_004;  // 0x004 [R/W] (ETweak, Read, Update)
    u32 m_field_008;  // 0x008 [R/W] (AddVal, ETweak, FileName, ...)
    u32 m_field_00C;  // 0x00C [R/W] (ETweak, Read, RemoveVal)
    u8 _pad_010[8];  // 0x010
    u32 m_field_018;  // 0x018 [R] (FileName, Read, Update, ...)
    u32 m_field_01C;  // 0x01C [W] (ETweak)
    u32 m_field_020;  // 0x020 [R] (FileName, Read, ~ETweak)
    u32 m_field_024;  // 0x024 [W] (ETweak)
};

#endif // ETWEAK_H
