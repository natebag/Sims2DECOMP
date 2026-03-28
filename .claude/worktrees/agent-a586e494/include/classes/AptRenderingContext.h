#ifndef APTRENDERINGCONTEXT_H
#define APTRENDERINGCONTEXT_H

#include "types.h"

// AptRenderingContext - struct layout extracted from assembly analysis
// Estimated minimum size: 0x3C0 (960 bytes)
// 16 known fields (0 named), 20 methods

class AptRenderingContext {
public:
    // Constructors / Destructors
    AptRenderingContext(void)  // 0x806FB290

    // Methods
    void pushVertexMatrix(void);  // 0x806FB760 (208B)
    void appendVertexMatrix(AptMatrix *);  // 0x806FBAA8 (112B)
    void popVertexMatrix(void);  // 0x806FB830 (240B)
    void expandBoundingRect(AptRect *, AptRect *);  // 0x806FBB18 (664B)
    void multMatrix(AptMatrix *, AptMatrix *, AptMatrix *);  // 0x806FB920 (392B)
    void getVertexMatrix(AptMatrix *);  // 0x806FB658 (264B)
    void pushColourTransform(void);  // 0x806FB370 (252B)
    void appendColourTransform(AptCXForm *);  // 0x806FB564 (244B)
    void popColourTransform(void);  // 0x806FB46C (248B)

    // ---- Field Layout (from assembly analysis) ----
    f32 m_field_000;  // 0x000 [R/W] (appendColourTransform, multMatrix, popColourTransform, ...)
    f32 m_field_004;  // 0x004 [R/W] (appendColourTransform, multMatrix, popColourTransform, ...)
    f32 m_field_008;  // 0x008 [R/W] (appendColourTransform, multMatrix, popColourTransform, ...)
    f32 m_field_00C;  // 0x00C [R/W] (appendColourTransform, multMatrix, popColourTransform, ...)
    f32 m_field_010;  // 0x010 [R/W] (appendColourTransform, multMatrix, popColourTransform, ...)
    f32 m_field_014;  // 0x014 [R/W] (appendColourTransform, multMatrix, popColourTransform, ...)
    f32 m_field_018;  // 0x018 [R/W] (appendColourTransform)
    f32 m_field_01C;  // 0x01C [R/W] (appendColourTransform)
    f32 m_field_020;  // 0x020 [R/W] (expandBoundingRect, getVertexMatrix, popVertexMatrix, ...)
    f32 m_field_024;  // 0x024 [R] (expandBoundingRect)
    f32 m_field_028;  // 0x028 [R] (expandBoundingRect)
    f32 m_field_02C;  // 0x02C [R] (expandBoundingRect)
    f32 m_field_030;  // 0x030 [R] (expandBoundingRect)
    f32 m_field_034;  // 0x034 [R] (expandBoundingRect)
    u8 _pad_038[0x380];  // 0x038
    u32 m_field_3B8;  // 0x3B8 [R/W] (popColourTransform, pushColourTransform)
    u32 m_field_3BC;  // 0x3BC [R/W] (getVertexMatrix, popVertexMatrix, pushVertexMatrix)
};

#endif // APTRENDERINGCONTEXT_H
