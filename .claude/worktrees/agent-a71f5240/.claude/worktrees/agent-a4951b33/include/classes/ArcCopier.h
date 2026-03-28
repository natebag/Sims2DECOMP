#ifndef ARCCOPIER_H
#define ARCCOPIER_H

#include "types.h"

// ArcCopier - struct layout extracted from assembly analysis
// Estimated minimum size: 0x10 (16 bytes)
// 4 known fields (1 named), 12 methods

class ArcCopier {
public:
    // Constructors / Destructors
    ArcCopier(void)  // 0x80877B60
    ~ArcCopier(void);  // 0x80877BA8

    // Methods
    void Copy(char *, char *, unsigned int &, int);  // 0x80877D20 (1268B)
    void TerminateCopy(void);  // 0x80878214 (40B)
    void ResumeCopy(void);  // 0x8087823C (40B)
    bool IsTerminatingCopy(void);  // 0x80878264 (44B)

    // ---- Field Layout (from assembly analysis) ----
    void** _vtable;  // 0x000 [R/W] - vtable pointer (Copy, ~ArcCopier)
    u32 m_field_004;  // 0x004 [R/W] (Copy, ~ArcCopier)
    u32 m_field_008;  // 0x008 [R/W] (Copy, ~ArcCopier)
    u32 m_field_00C;  // 0x00C [R/W] (Copy, ~ArcCopier)
};

#endif // ARCCOPIER_H
