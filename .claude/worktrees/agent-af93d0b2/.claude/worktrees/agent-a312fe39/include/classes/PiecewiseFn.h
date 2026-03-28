#ifndef PIECEWISEFN_H
#define PIECEWISEFN_H

#include "types.h"

// PiecewiseFn - struct layout extracted from assembly analysis
// Estimated minimum size: 0x10 (16 bytes)
// 4 known fields (4 named), 14 methods

class PiecewiseFn {
public:
    // Constructors / Destructors
    PiecewiseFn(void)  // 0x80383264
    ~PiecewiseFn(void);  // 0x803832AC

    // Methods
    /* ? */ GetValue(float);  // 0x8024EBB4 (536B)
    void SetMaxPoints(int);  // 0x80383330 (240B)
    void AddPointsFromText(char *);  // 0x80383684 (652B)
    void Reset(void);  // 0x80383308 (40B)
    void AddPoint(PiecewisePt &);  // 0x80383420 (612B)
    void UpdateReciprocals(void);  // 0x80383910 (172B)

    // ---- Field Layout (from assembly analysis) ----
    void** _vtable;  // 0x000 [R/W] - vtable pointer (AddPoint, SetMaxPoints)
    u32 m_maxPoints_004;  // 0x004 [R/W] (AddPoint, SetMaxPoints)
    u32 m_maxPoints_008;  // 0x008 [R/W] (AddPoint, SetMaxPoints)
    u32 m_maxPoints_00C;  // 0x00C [R/W] (AddPoint, SetMaxPoints)
};

#endif // PIECEWISEFN_H
