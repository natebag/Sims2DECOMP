#ifndef FADESQUARE_H
#define FADESQUARE_H

#include "types.h"

// FadeSquare - struct layout extracted from assembly analysis
// Estimated minimum size: 0x440 (1088 bytes)
// 8 known fields (0 named), 17 methods

class FadeSquare {
public:
    // Constructors / Destructors
    FadeSquare(void)  // 0x805F49A8
    ~FadeSquare(void);  // 0x805F4A1C

    // Methods
    void ShouldDraw(void);  // 0x805F4C30 (72B)
    void Draw(ERC *, EVec3 &);  // 0x805F4C78 (720B)
    void StopDraw(void);  // 0x805F4B34 (52B)
    void StartDraw(EVec3 &, bool);  // 0x805F4AA4 (104B)
    void StartFade(void);  // 0x805F4B0C (40B)
    void Update(float);  // 0x805F4B68 (200B)
    /* ? */ GetPos(void);  // 0x805FB374 (40B)

    // ---- Field Layout (from assembly analysis) ----
    u8 _pad_000[4];  // 0x000
    f32 m_field_004;  // 0x004 [R] (Draw)
    f32 m_field_008;  // 0x008 [R] (Draw)
    u32 m_field_00C;  // 0x00C [R/W] (Draw, FadeSquare, Update, ...)
    f32 m_field_010;  // 0x010 [R/W] (Draw, Update)
    u32 m_field_014;  // 0x014 [R] (Update)
    u32 m_field_018;  // 0x018 [R/W] (Draw, Update)
    u8 _pad_01C[0x3FC];  // 0x01C
    f32 m_field_418;  // 0x418 [R] (Draw)
    u8 _pad_41C[0x20];  // 0x41C
    f32 m_field_43C;  // 0x43C [R] (Draw)
};

#endif // FADESQUARE_H
