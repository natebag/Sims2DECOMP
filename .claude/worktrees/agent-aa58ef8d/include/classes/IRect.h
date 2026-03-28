#ifndef IRECT_H
#define IRECT_H

#include "types.h"

// IRect - struct layout extracted from assembly analysis
// Estimated minimum size: 0x10 (16 bytes)
// 4 known fields (4 named), 11 methods

class IRect {
public:
    // Constructors / Destructors
    IRect(void)  // 0x803ACA88
    ~IRect(void);  // 0x803A6DEC

    // Methods
    bool IsContained(IRect *);  // 0x80201874 (132B)
    void Intersect(IRect *, IRect *);  // 0x802018F8 (516B)
    bool IsEmpty(void);  // 0x80201AFC (84B)
    void Set(int, int, int, int);  // 0x803ACAFC (64B)
    void Inflate(int, int);  // 0x803ACB94 (88B)
    void Offset(int, int);  // 0x803ACB3C (88B)
    void PointIn(IPoint);  // 0x803E4494 (164B)

    // ---- Field Layout (from assembly analysis) ----
    void** _vtable;  // 0x000 [R/W] - vtable pointer (Intersect, IsContained)
    u32 m_bIsContained_004;  // 0x004 [R/W] (Intersect, IsContained)
    u32 m_bIsContained_008;  // 0x008 [R/W] (Intersect, IsContained)
    u32 m_bIsContained_00C;  // 0x00C [R/W] (Intersect, IsContained)
};

#endif // IRECT_H
