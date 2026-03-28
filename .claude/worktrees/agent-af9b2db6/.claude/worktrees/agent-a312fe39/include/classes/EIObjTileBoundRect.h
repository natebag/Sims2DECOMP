#ifndef EIOBJTILEBOUNDRECT_H
#define EIOBJTILEBOUNDRECT_H

#include "types.h"

// EIObjTileBoundRect - struct layout extracted from assembly analysis
// Estimated minimum size: 0x10 (16 bytes)
// 4 known fields (0 named), 23 methods

class EIObjTileBoundRect {
public:
    // Constructors / Destructors
    EIObjTileBoundRect(void)  // 0x800F4F38
    EIObjTileBoundRect(CTilePt &)  // 0x80102D08
    EIObjTileBoundRect(EVec4 &)  // 0x80102D58
    ~EIObjTileBoundRect(void);  // 0x800F4F88

    // Methods
    void Set(CTilePt &);  // 0x80101EB8 (244B)
    void AddTilePt(CTilePt &);  // 0x801018E8 (720B)
    /* ? */ GetCenter(EVec2 &);  // 0x80102138 (260B)
    void PtInRect(CTilePt &);  // 0x80102080 (184B)
    void AddTilePt(EVec2 &);  // 0x80101BB8 (768B)
    void PtInRect(float, float);  // 0x80102DF4 (200B)
    void Set(EVec2 &);  // 0x80101FAC (212B)
    void Overlap(EIObjTileBoundRect &);  // 0x8010223C (804B)
    void Scale(float, float);  // 0x80102560 (616B)
    void MirrorYX(void);  // 0x801027C8 (428B)

    // ---- Field Layout (from assembly analysis) ----
    f32 m_field_000;  // 0x000 [R/W] (AddTilePt, MirrorYX, Overlap, ...)
    f32 m_field_004;  // 0x004 [R/W] (AddTilePt, MirrorYX, Overlap, ...)
    f32 m_field_008;  // 0x008 [R/W] (AddTilePt, MirrorYX, Overlap, ...)
    f32 m_field_00C;  // 0x00C [R/W] (AddTilePt, MirrorYX, Overlap, ...)
};

#endif // EIOBJTILEBOUNDRECT_H
